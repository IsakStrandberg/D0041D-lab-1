
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Students {
private:
	vector<string> studentName;
public:
	void getStudentName() {
		for(int i=0; i<studentName.size(); i++){
			cout << studentName[i] << ", ";
		}
		cout << "\n";
	}

	string getSingleStudent(int i) {
		return(studentName[i]);
	}

	int getSize() {
		return(studentName.size());
	}

	void deleteStudent(int i) {
		studentName.erase(studentName.begin() + i);
	}

	void addStudentName(string name) {
		studentName.push_back(name);
	}
};

class StudentClass {
private:
	string courseName;
public:
	StudentClass() {
		string courseName = "";
		Students* student = nullptr;
		StudentClass* next = nullptr;
	};

	StudentClass* next;
	Students* object;

	string getCourseName() {
		return(courseName);
	}
	void setCourseName(string cName) {
		courseName = cName;
	}

	/*Students getObject() {
		return(*object);
	}*/
	void setObject(Students& o) {
		object = &o;
	}

	/*CourseNode setNext(CourseNode& n) {
		next = &n;
	}
	CourseNode getNext() {
		return(*next);
	}*/
};

class LinkedList {
private:
	StudentClass* head;
	StudentClass* tail;
public:
	LinkedList() {
		StudentClass* head = nullptr;
		StudentClass* tail = nullptr;
	}

	void AddNode(string name,string studentName) {
		bool exist = false;
		StudentClass* check;
		check = head;
		while (check != nullptr) {
			if (check->getCourseName() == name) {
				exist = true;
				check->object->addStudentName(studentName);
				cout << "Student has been added to the selected course \n";
				break;
			}
			else {
				check = check->next;
			}
		}

		if (exist == false) {
			StudentClass* temporary = new StudentClass;
			temporary->setCourseName(name);
			temporary->next = nullptr;
			if (head == nullptr) {
				head = temporary;
				tail = temporary;
			}
			else {
				tail->next = temporary;
				tail = tail->next;
			}
			Students* newApplication = new Students;
			newApplication->addStudentName(studentName);
			temporary->setObject(*newApplication);
			cout << "Student has been added to the selected course \n";
		}
	}

	void Print() {
		StudentClass* printTemp;
		printTemp = head;
		while (printTemp != nullptr) {
			cout << "\n" << printTemp->getCourseName() << ": ";
			printTemp->object->getStudentName();

			printTemp = printTemp->next;
		}
	}

	void Delete(string name, string student) {
		bool exist = false;
		StudentClass* check;
		check = head;
		while (check != nullptr) {
			if (check->getCourseName() == name) {
				exist = true;
				break;
			}
			else {
				check = check->next;
			}
		}

		if (exist == false) {
			cout << "Course does not exist \n";
			return;
		}
		else {
			int size = check->object->getSize();
			for (int x = 0; x < size; x++) {
				if (check->object->getSingleStudent(x) == student) {
					check->object->deleteStudent(x);
					break;
				}
				cout << "Student did not exist or is not in this course\n";
			}
		}
	}
};

//	void Delete(string name) {
//		bool exist = false;
//		StudentClass* check;
//		check = head;
//		while (check != nullptr) {
//			if (check->getCourseName() == name) {
//				exist = true;
//				break;
//			}
//			else {
//				check = check->next;
//			}
//		}
//
//		if (exist == false) {
//			cout << "Course does not exist \n";
//		}
//		else {
//			StudentClass* findPrev;
//			findPrev = head;
//			while (findPrev != nullptr) {
//				if (findPrev->next->getCourseName() == name) {
//					break;
//				}
//				else {
//					check = check->next;
//				}
//			}
//			StudentClass* deleteTemp;
//			deleteTemp = findPrev->next;
//
//			findPrev->next = deleteTemp->next;
//			//delete Students
//			delete deleteTemp;
//		}
//	}
//};