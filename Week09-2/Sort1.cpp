#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (int i = 0; i < commands.size(); i++)
	{
		int s = commands[i][0];
		int e = commands[i][1];
		int k = commands[i][2];

		vector<int> crop;
		for (int j = s - 1; j <= e - 1; j++)
		{
			crop.push_back(array[j]);

		}
		sort(crop.begin(), crop.end());


		answer.push_back(crop[k - 1]);

	}


	return answer;
}