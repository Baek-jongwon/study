#include <string>
#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;


vector<int> solution(vector<string> operations) {
	vector<int> answer;
	int size = operations.size();


	deque<int> dq;

	for (int i = 0; i < size; i++)
	{
		string str = operations[i];
		string s = "";
		if (str[0] == 'I')
		{
			for (int j = 2; j < str.length(); j++)
			{
				s += str[j];
			}
			dq.push_back(stoi(s));
			sort(dq.begin(), dq.end());
		}
		else if (str == "D 1")
		{
			if (!dq.empty())dq.pop_back();
		}
		else if (str == "D -1") {
			if (!dq.empty())dq.pop_front();
		}


	}
	if (!dq.empty())
	{
		answer.push_back(dq.back());
		answer.push_back(dq.front());
	}
	else {
		answer.push_back(0);
		answer.push_back(0);
	}




	return answer;
}