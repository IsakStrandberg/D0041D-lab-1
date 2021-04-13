

#include <iostream>
#include <string>
#include "D0041D lab 1.h"
using namespace std;

void main() {
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