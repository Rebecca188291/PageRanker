#include <iostream>
#include <string>
#include "graph.h"
using namespace std;

int main()
{
	int numLines, p;
	string from, to;
	cin >> numLines;
	cin >> p;

	cout << "numLines: " << numLines << endl;
	graph PageRanker(p);

	for (int i = 0; i < numLines; i++)
	{
		cin >> from;
		cin >> to;
		PageRanker.insert(from, to);
	}

	//cout << "num Lines: " << numLines << endl;
	//cout << "p: " << p << endl;

	PageRanker.printPR();

}
