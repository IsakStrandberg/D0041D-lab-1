

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Object {
private:
	vector<string> studentName;

public:
	string getStudentName(int number) {
		return(studentName[number]);
	}

	void addStudentName(string name) {
		studentName.push_back(name);
	}
};

class CourseNode {

private:
	string courseName;
	CourseNode* object;
	CourseNode* next;
	CourseNode* head;
	CourseNode* tail;

public:
	CourseNode() {
		string courseName = "";
		CourseNode* object = NULL;
		CourseNode* next = NULL;
		CourseNode* head = NULL;
		CourseNode* tail = NULL;
	};

	string getCourseName() {
		return(courseName);
	}
	void setCourseName(string cName) {
		courseName = cName;
	}

	CourseNode setObject() {
		return(*object);
	}
	void setObject(CourseNode& o) {
		object = &o;
	}

	CourseNode setNext() {
		return(*next);
	}
	void getNext(CourseNode& n) {
		next = &n;
	}

	CourseNode setHead() {
		return(*head);
	}
	void getHead(CourseNode& h) {
		next = &h;
	}

	CourseNode setTail() {
		return(*tail);
	}
	void getTail(CourseNode& t) {
		next = &t;
	}

};