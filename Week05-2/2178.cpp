#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, m;
bool visited[101][101];
int dis[101][101];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };


void bfs(int y, int x)
{
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	visited[y][x] = false;
	dis[y][x] = 1;
	while (!q.empty())
	{
		int y, x;
		y = q.front().first;
		x = q.front().second;
		q.pop();
		
		if (y == n && x == m)
		{
			cout << dis[y][x];
			return;
		}
		int new_y, new_x;
		for (int i = 0; i < 4; i++)
		{
			new_y = y + dy[i];
			new_x = x + dx[i];

			if (new_y > 0 && new_y <= n && new_x > 0 && new_x <= m)
			{
				if (visited[new_y][new_x])
				{
					visited[new_y][new_x] = false;
					q.push(make_pair(new_y, new_x));
					dis[new_y][new_x] = dis[y][x] + 1;
				}
			}
		}
	}
}


int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		for (int j = 1; j <= m; j++)
		{
			int num;
			num = str[j - 1] - '0';
			if (num == 1)
			{
				visited[i][j] = true;
			}
			
		}
	}
	bfs(1, 1);
}
