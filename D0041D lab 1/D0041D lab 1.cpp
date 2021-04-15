

#include <iostream>
#include <string>
#include "D0041D lab 1.h"
#include <chrono>
using namespace std::chrono;
using namespace std;

void basicTest() {
	LinkedList test;

	test.AddNode("math","Isak Strandberg");
	test.AddNode("maths","petter");
	test.AddNode("math","jesse");
	test.AddNode("lunch", "jesse");
	test.AddNode("lunch", "alexander");

	test.Print();

	test.Delete("lunch", "jesse");

	test.Print();

	test.Delete("bioshcik", "isak");
	test.Delete("math", "Isak Strandberg");
	test.Delete("math", "Isak Strandberg");
	test.Delete("lunch", "alexander");
	test.Delete("maths", "petter");

	test.Print();
}

void generateDatabase(LinkedList& database, int courses, int students) {
	for (int i = 0; i < courses; i++) {
		string course = to_string(i);
		for (int x = 0; x < students; x++) {
			string student = to_string(x);
			database.AddNode(course, student);
		}
	}
}

void testAddNode(string course, string student) {
	high_resolution_clock::duration totalTime(0);
	for (int i = 0; i < 10; i++) {
		LinkedList database;
		generateDatabase(database, 100, 100);
		auto start = high_resolution_clock::now();
		database.AddNode(course, student);
		auto end = high_resolution_clock::now();
		totalTime = totalTime + (end - start);
	}
	auto average = totalTime.count() / 10;
	cout << "the average time is: " << average << " nanoseconds\n";
}

void testDelete(string course, string student) {
	high_resolution_clock::duration totalTime(0);
	for (int i = 0; i < 10; i++) {
		LinkedList database;
		generateDatabase(database, 100, 100);
		auto start = high_resolution_clock::now();
		database.Delete(course, student);
		auto end = high_resolution_clock::now();
		totalTime = totalTime + (end - start);
	}
	auto average = totalTime.count() / 10;
	cout << "the average time is: " << average << " nanoseconds\n";
}

void main() {
	//testAddNode("99", "per");
	testDelete("99", "0");
}