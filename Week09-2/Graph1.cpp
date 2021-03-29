#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;


int bfs(int start, int cnt, vector<int> v[], vector<int> arr)
{
	int count = 0;
	queue<pair<int, int> > q;
	q.push({ start , cnt });
	arr[start] = cnt;
	while (!q.empty())
	{
		int node = q.front().first;
		int cnt = q.front().second;
		count = cnt;
		q.pop();
		for (int i = 0; i < v[node].size(); i++)
		{
			int nextnode = v[node][i];
			if (nextnode == 1) continue;
			if (!arr[nextnode])
			{
				arr[nextnode] = cnt + 1;
				q.push({ nextnode ,cnt + 1 });
			}
		}
	}
	int ret = 0;
	for (int i = 1; i < arr.size(); i++)
	{
		if (arr[i] == count) ret++;
	}

	return ret;
}


int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	vector<int> v[n + 1];
	vector<int> arr(n + 1);

	for (int i = 0; i < edge.size(); i++)
	{

		v[edge[i][0]].push_back(edge[i][1]);
		v[edge[i][1]].push_back(edge[i][0]);
	}


	answer = bfs(1, 0, v, arr);


	return answer;
}