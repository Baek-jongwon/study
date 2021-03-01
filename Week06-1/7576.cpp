#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int M, N;
int visited[1001][1001];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

queue<pair<int, int>> q;

void bfs()
{
	while (!q.empty())
	{
		int y, x;
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int new_y, new_x;
			new_y = y + dy[i];
			new_x = x + dx[i];

			if (new_y > 0 && new_y <= M && new_x > 0 && new_x <= N)
			{
				if (visited[new_y][new_x]==0)
				{
					visited[new_y][new_x] = visited[y][x]+1;
					q.push(make_pair(new_y, new_x));
				}
			}
 		}
	}
}


int main()
{
	cin >> N >> M;
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int num;
			cin >> num;
			if (num == 1)
			{
				q.push(make_pair(i, j));
				visited[i][j] = num;
			}
			else if (num == -1)
			{
				visited[i][j] = -1;
			}
		}
	}
	bfs();
	int maxx = 0;
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (visited[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
			maxx= maxx<visited[i][j] ? visited[i][j] : maxx;
		}
	}
	cout << maxx - 1;
}



