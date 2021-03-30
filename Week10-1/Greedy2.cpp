#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string name) {
	int answer = 0, idx = 0;
	string s(name.length(), 'A');

	while (1)
	{
		s[idx] = name[idx];

		if (name[idx] - 'A' < 'Z' - name[idx] + 1)
		{
			answer += name[idx] - 'A';
		}
		else answer += 'Z' - name[idx] + 1;

		if (s == name) break;

		for (int i = 1; i < name.length(); i++)
		{
			if (name[(idx + i) % name.length()] != s[(idx + i) % name.length()])
			{
				idx = (idx + i) % name.length();
				answer += i;
				break;

			}
			else if (name[(name.length() + idx - i) % name.length()] != s[(name.length() + idx - i) % name.length()])
			{
				idx = (name.length() + idx - i) % name.length();
				answer += i;
				break;
			}
		}



	}


	return answer;
}