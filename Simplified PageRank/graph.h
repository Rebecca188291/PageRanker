#pragma once
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <iomanip> 
using namespace std;

class graph
{
private:
	//maybe a map with name with the val being a pair of its rank & vector of what is linking TO it
	map<string, pair<float, vector<string>>> website;
	int size = 0;
	int p = 0;
	map<string, int> fromCounter;

public:
	graph(int Size, int P)
	{
		size = Size;
		p = P;
	}
	void insert(string from, string to); 
	void printPR();
	void updateRank(); //after inserting something new, it's possible all the ranks change, so we'll update all


//function to print
};

