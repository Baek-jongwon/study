#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

struct Info {
	int ry, rx, by, bx, cnt;
};

char map[10][11];

Info start;

int bfs()
{
	int visited[10][10][10][10] = { 0, };
	
	queue<Info> q;
	q.push(start);
	visited[start.ry][start.rx][start.by][start.bx] = 1;

	const int dy[] = { -1 , 1 , 0 , 0 };
	const int dx[] = { 0 , 0 , -1 , 1 };
	int ret = -1;
	while (!q.empty())
	{
		Info cur = q.front(); 
		q.pop();
		if (cur.cnt > 10) break;
		if (map[cur.ry][cur.rx] == 'O' && map[cur.by][cur.bx] != 'O')
		{
			ret = cur.cnt;
			break;
		}

		for (int dir = 0; dir < 4; dir++)
		{
			int next_ry = cur.ry;
			int next_rx = cur.rx;
			int next_by = cur.by;
			int next_bx = cur.bx;
			
			
			while (1)
			{
				if (map[next_ry][next_rx] != '#' && map[next_ry][next_rx] != 'O')
				{
					next_ry += dy[dir], next_rx += dx[dir];
				}
				else {
					if (map[next_ry][next_rx] == '#')
					{
						next_ry -= dy[dir], next_rx -= dx[dir];
					}
					break;
				}
				
			}
			while (1)
			{
				if (map[next_by][next_bx] != '#' && map[next_by][next_bx] != 'O')
				{
					next_by += dy[dir], next_bx += dx[dir];
				}
				else {
					if (map[next_by][next_bx] == '#')
					{
						next_by -= dy[dir], next_bx -= dx[dir];
					}
					break;
				}
				
			}

			if (next_ry==next_by && next_rx ==next_bx)
			{
				if (map[next_ry][next_rx] != 'O')
				{
					int r_dist = abs(next_ry - cur.ry) + abs(next_rx - cur.rx);
					int b_dist = abs(next_by - cur.by) + abs(next_bx - cur.bx);

					if (r_dist < b_dist)
					{
						next_by -= dy[dir], next_bx -= dx[dir];
					}
					else
					{
						next_ry -= dy[dir], next_rx -= dx[dir];
					}
				}
				
			}
			if (visited[next_ry][next_rx][next_by][next_bx] == 0)
			{
				visited[next_ry][next_rx][next_by][next_bx] = 1;
				Info next;
				next.ry = next_ry;
				next.rx = next_rx;
				next.by = next_by;
				next.bx = next_bx;
				next.cnt = cur.cnt + 1;
				q.push(next);

			}
		}
	}
	return ret;
}


int main()
{

	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", map[i]);
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (map[i][j] == 'R')
			{
				start.ry = i;
				start.rx = j;
			}
			if (map[i][j] == 'B')
			{
				start.by = i;
				start.bx = j;
			}
		}
	}
	start.cnt = 0;

	int out = bfs();

	printf("%d", out);
}