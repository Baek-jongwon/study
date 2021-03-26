#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	unordered_map<string, int> m;

	for (string name : participant)
	{
		m[name]++;
	}

	for (string name : completion)
	{
		m[name]--;
	}

	for (pair<string, int> cant : m)
	{
		if (cant.second > 0)
		{
			answer = cant.first;
		}
	}

	return answer;
}