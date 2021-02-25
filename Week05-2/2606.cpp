#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool visited[101];
vector<int> v[101];
int cnt=0;

void bfs(int curr)
{
	queue<int> q;
	visited[curr] = true;
	q.push(curr);

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		
		for (int i = 0; i < v[x].size(); i++)
		{
			int y = v[x][i];
			if (!visited[y])
			{
				visited[y] = true;
				q.push(y);
				cnt++;
			}
		}

	}
}


int main()
{
	int n,m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int p, c;

		cin >> p >> c;
		
		v[p].push_back(c);
		v[c].push_back(p);
	}
	
	bfs(1);
	cout << cnt;
}