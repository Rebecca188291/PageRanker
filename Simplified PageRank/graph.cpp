#include "graph.h"
void graph::insert(string from, string to)
{

	if (website.find(to) == website.end())
	{
		vector<string> linkedBy;
		linkedBy.push_back(from);
		pair<double, vector<string>> pair1;
		pair1.first = 1.0;
		pair1.second = linkedBy;
		website[to] = pair1;

		if (website.find(from) == website.end())
		{
			pair<double, vector<string>> pair2;
			pair2.first = 1.0;
			website[from] = pair2;
			fromCounter[from] = 1.0;
		}
		else
		{
			fromCounter[from]++;
		}
	}
	else
	{
		website[to].second.push_back(from);
		if (website.find(from) == website.end())
		{
			pair<double, vector<string>> pair2;
			pair2.first = 1.0;
			website[from] = pair2;
			fromCounter[from] = 1.0;
		}
		else
		{
			fromCounter[from]++;
		}
	}
}

void graph::printPR()
{
	//create a vector of pairs
	//iterate through map and push back all ranks and urls (iter.second.first i think)
	// sort based on floats
	// iterate through vector and print out everything
	updateRank();
	vector<pair<string, double>> finalList;
	for (auto iter : website)
	{
		pair<string, double> pair1;
		pair1.second = iter.second.first;
		pair1.first = iter.first;
		finalList.push_back(pair1);
		//cout << iter.first << ": ";
		//for (int j = 0; j < iter.second.second.size(); j++)
		//{
		//	cout << iter.second.second[j]<< " ";
		//}
		//cout << endl;
	}
	sort(finalList.begin(), finalList.end()); //sorts based on the name
	for (int i = 0; i < finalList.size(); i++)
	{
		cout << finalList[i].first << " " << fixed << setprecision(2) << finalList[i].second << endl;
	}
	//for (auto iter : fromCounter)
	//{
	//	cout << "from:" << iter.first << endl;
	//}

}

void graph::updateRank()
{
	//add any websites that point to nothing
	for (auto &iter : website)
	{
		if (fromCounter.find(iter.first) == fromCounter.end())
		{
			fromCounter[iter.first] = 1.0;
		}
		iter.second.first = 1.0 / website.size();
	}
	for (int i = 0; i < p-1; i++)
	{
		vector<double> ranks;
		for (auto &iter : website)
		{
			double sum = 0.0;
			//for every website, calculate all the out degrees of what is pointing to it
			for (int j = 0; j < iter.second.second.size(); j++)
			{
				string from = iter.second.second[j];
				sum +=  website[from].first * (1.0 / fromCounter[from]);
			}
			ranks.push_back(sum);
			// iter.second.first = sum;
		}
		int counter = 0;
		for (auto& iter : website)
		{
			iter.second.first = ranks[counter];
			counter++;
		}
	}

}
