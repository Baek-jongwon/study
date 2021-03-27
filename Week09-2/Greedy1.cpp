#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	int lost_idx = 0;
	queue<int> q;
	sort(lost.begin(), lost.end());
	sort(reserve.begin(), reserve.end());
	int cnt = 0;
	int cnt2 = 0;
	int cnt3 = 0;
	for (int i = 0; i < reserve.size(); i++)
	{
		bool check = false;
		for (int j = 0; j < lost.size(); j++)
		{
			if (reserve[i] == lost[j])
			{
				lost[j] = -1;
				check = true;
				cnt2++;
			}
		}
		if (!check) q.push(reserve[i]);

	}
	cnt3 = q.size();

	while (!q.empty())
	{
		int a = q.front();
		q.pop();

		for (int i = lost_idx; i < lost.size(); i++)
		{
			if (a + 1 == lost[i])
			{
				cnt++;
				lost[i] = -1;
				break;
			}
			else if (a - 1 == lost[i])
			{
				cnt++;
				lost[i] = -1;
				break;
			}
		}

	}
	if (cnt2 > 0) answer = n - lost.size() + cnt2 + cnt;
	else answer = n - lost.size() + cnt;
	return answer;
}