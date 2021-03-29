#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;


bool comp(string a, string b)
{
	return a + b > b + a;
}



string solution(vector<int> numbers) {
	string answer = "";
	vector<string> s;
	for (auto n : numbers)
	{
		s.push_back(to_string(n));
	}

	sort(s.begin(), s.end(), comp);
	if (s[0] == "0") return "0";
	for (auto c : s)
	{
		answer += c;
	}

	return answer;
}
