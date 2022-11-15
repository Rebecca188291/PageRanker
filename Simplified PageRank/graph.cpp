#include "graph.h"
void graph::insert(string from, string to)
{
	if (fromCounter.count(from) == 0)
	{
		fromCounter[from] = 1;
	}
	else
	{
		fromCounter[from]++;
	}

	if (website.find(to) == website.end())
	{
		//then it is not in the map
		vector<string> linkedBy;
		pair<float, vector<string>> pair1;
		pair1.first = 1.0/size;
		pair1.second = linkedBy;
		linkedBy.push_back(from);
		website[to] = pair1;

		if (website.find(from) == website.end())
		{
			vector<string> linkingTo;
			pair<float, vector<string>> pair2;
			pair2.first = 1.0/size;
			pair2.second = linkingTo;
			website[from] = pair2;
		}
	}
	else
	{
		website[to].second.push_back(from);
		if (website.find(from) == website.end())
		{
			vector<string> linkingTo;
			pair<float, vector<string>> pair2;
			pair2.first = 1.0/size;
			pair2.second = linkingTo;
			website[from] = pair2;
		}
	}
}

void graph::printPR()
{
	//create a vector of pairs
	//iterate through map and push back all ranks and urls (iter.second.first i think)
	// sort based on floats
	// iterate through vector and print out everything
	vector<pair<string, float>> finalList;
	for (auto iter : website)
	{
		pair<string, float> pair1;
		pair1.second = iter.second.first;
		pair1.first = iter.first;
		finalList.push_back(pair1);
	}
	sort(finalList.begin(), finalList.end()); //sorts based on the name
	for (int i = 0; i < finalList.size(); i++)
	{
		cout << finalList[i].first << " " << fixed << setprecision(2) << finalList[i].second << endl;
	}

}

void graph::updateRank()
{
	//the rank is initially 1/V where V is # vertices;
}
