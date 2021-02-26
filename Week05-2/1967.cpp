#include <iostream>
#include <queue>
#include <vector>
#include<cstring>
using namespace std;

bool visited[10001];
vector<pair<int,int>> v[10001];
int start_node;
int max_length[10001];
int maxx;
int n, p, c, w;

void bfs(int curr)
{
	queue<int> q;
	q.push(curr);

	visited[curr] = true;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		for (int i = 0; i < v[x].size(); i++)
		{
			int y = v[x][i].first;
			if (!visited[y])
			{
				visited[y] = true;
				q.push(y);
				max_length[y] = v[x][i].second + max_length[x];
				if (max_length[y] > maxx)
				{
					maxx = max_length[y];
					start_node = y;
				}
			}
		}
	}
}


int main()
{
	cin >> n;

	for (int i = 1; i < n; i++)
	{
		cin >> p >> c >> w;

		v[p].push_back(make_pair(c,w));
		v[c].push_back(make_pair(p, w));
		
	}

	bfs(1);

	memset(visited,  0, sizeof(visited));
	memset(max_length,  0, sizeof(max_length));
	maxx = 0;
	
	bfs(start_node);
	cout << maxx;
}