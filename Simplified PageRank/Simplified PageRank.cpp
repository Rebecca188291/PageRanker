#include <iostream>
#include <string>
#include "graph.h"
using namespace std;

int main()
{
	graph Test(6, 2);
	Test.insert("A", "B");
	Test.insert("A", "C");
	Test.insert("C", "D");
	Test.printPR();

}
