#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

vector<pair<int, int>> v[10001];
bool visited[10001];
int start, finish;

bool bfs(int weight)
{
	queue<int> q;
	q.push(start);
	visited[start]=true;
	
	while (!q.empty())
	{
		int factory = q.front();
		q.pop();

		if (factory == finish)
		{
			return true;
		}
		for (int i = 0; i < v[factory].size(); i++)
		{
			int next_factory = v[factory][i].first;
			int next_weight = v[factory][i].second;
			
			if (!visited[next_factory] && weight <= next_weight)
			{
				visited[next_factory] = true;
				q.push(next_factory);
			}
		}
	}
	return false;
}


int main()
{
	int n, m;
	cin >> n >> m;
	int max_w=0;
	for (int i = 0; i < m; i++)
	{
		int p, c , w;
		cin >> p >> c >> w;
		v[p].push_back(make_pair(c, w));
		v[c].push_back(make_pair(p, w));
		max_w = max(max_w, w);
	}
	cin >> start >> finish;

	int low = 1;
	int high = max_w;
	while (low <= high)
	{
		memset(visited, false, sizeof(visited));

		int mid = (low + high) / 2;

		if (bfs(mid))
		{
			low = mid + 1;
		}
		else high = mid - 1;
	}
	cout << high;
}
