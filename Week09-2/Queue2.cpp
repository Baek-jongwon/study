#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;

	queue<int> q;

	for (int i = 0; i < prices.size(); i++)
	{
		q.push(prices[i]);
	}
	int idx = 1;
	while (!q.empty())
	{
		int price = q.front(); q.pop();
		int cnt = 0;
		for (int i = idx; i < prices.size(); i++)
		{
			if (price <= prices[i]) cnt++;
			else
			{
				cnt++;
				break;
			}
		}
		answer.push_back(cnt);
		idx++;



	}
	return answer;
}