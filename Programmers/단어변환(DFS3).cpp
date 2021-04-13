#include <string>
#include <vector>
#include <iostream>
using namespace std;
int answer = 100;

void dfs(string begin, string target, vector<string> words, vector<bool>& check, int depth)
{
	for (int i = 0; i < words.size(); i++)
	{
		int cnt = 0;
		for (int j = 0; j < words[i].length(); j++)
		{
			if (!check[i] && words[i][j] != begin[j]) cnt++;
		}
		if (cnt == 1)
		{
			if (target == words[i])
			{
				answer = depth + 1;
			}

			check[i] = true;
			dfs(words[i], target, words, check, depth + 1);
			check[i] = false;
		}
	}



}


int solution(string begin, string target, vector<string> words) {
	vector<bool> check(words.size(), false);
	int cnt = 0;
	dfs(begin, target, words, check, cnt);
	if (answer == 100) return 0;

	return answer;
}