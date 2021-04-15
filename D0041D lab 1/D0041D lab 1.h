
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Stack {
private:
	vector<string> studentName;
public:
	void Push(string name) {
		studentName.push_back(name);
	}

	void DeleteStudent(int i) {
		studentName.erase(studentName.begin() + i);
	}

	string GetSingleStudent(int i) {
		return(studentName[i]);
	}

	void Pop(int i) {
		vector<string> temp;
		for (int x = getSize(); x > i; x--) {
			if (x - 1 == i) {
				DeleteStudent(x - 1);
				break;
			}
			string tempName = GetSingleStudent(x - 1);
			temp.push_back(tempName);
			DeleteStudent(x - 1);
		}

		for (int y = temp.size(); y > 0; y--) {
			Push(temp[y - 1]);
		}
	}

	void getStudentName() {
		for(int i = studentName.size(); i > 0; i--){
			cout << studentName[i - 1] << ", ";
		}
		cout << "\n";
	}

	int getSize() {
		return(studentName.size());
	}
};

class Queue {
private:
	vector<string> studentName;
public:
	Queue() {
		
	};
	void enqueue(string name){
		studentName.push_back(name);
	}
	void dequeue(int i){// i = 0
		vector<string>temp;
		//studentName.pop_back();
		for(int k=i+1; k<getSize(); k++){ 
			temp.push_back(studentName[k]);
			studentName.pop_back();
		}
		studentName.pop_back();
		for(int k=0; k<temp.size(); k++){
			studentName.push_back(temp[k]);
		}
		//delete everything until i, save i and rest, then add back to list
	}
	string front(){
		return studentName[0];
	}
	string back(){
		return studentName[-1];
	}
	string GetSingleStudent(int i) {
		return(studentName[i]);
	}
	void getStudentName(){
		for(int i=0; i<studentName.size(); i++){
			cout << studentName[i] << ", ";
		}
		cout << "\n";
	}
	int getSize(){
		return(studentName.size());
	}
};

class StudentClass {
private:
	string courseName;

public:

	StudentClass* next = nullptr;
	//Stack* object = nullptr;
	Queue* object = nullptr;

	string getCourseName() {
		return(courseName);
	}
	void setCourseName(string cName) {
		courseName = cName;
	}

	/*Students getObject() {
		return(*object);
	}*/
	void setObject(Queue& o) {//Queue
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
	StudentClass* head = nullptr;
	StudentClass* tail = nullptr;
public:

	void AddNode(string name,string studentName) {
		bool exist = false;
		StudentClass* check;
		check = head;
		while (check != nullptr) {
			if (check->getCourseName() == name) {
				exist = true;
				check->object->enqueue(studentName);//enqueue instead of push
				//cout << "Student has been added to the selected course \n";
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
			Queue* newApplication = new Queue;//Stack/Queue
			newApplication->enqueue(studentName);//Push/enqueue
			temporary->setObject(*newApplication);
			//cout << "Student has been added to the selected course \n";
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
				if (check->object->GetSingleStudent(x) == student) {
					check->object->dequeue(x);//Pop/dequeue
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