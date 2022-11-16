#include <iostream>
#include <string>
#include "graph.h"
using namespace std;

int main()
{
	string numCommands;
	getline(cin, numCommands);
	for (int i = 0; i < numCommands.length(); i++)
	{

	}


	graph Test(2);
	Test.insert("google.com", "gmail.com");
	Test.insert("google.com", "maps.com");
	Test.insert("facebook.com", "ufl.edu");
	Test.insert("ufl.edu", "google.com");
	Test.insert("ufl.edu", "gmail.com");
	Test.insert("maps.com", "facebook.com");
	Test.insert("gmail.com", "maps.com");
	Test.printPR();

}
