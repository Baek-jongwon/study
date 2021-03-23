#include <iostream>
#include <queue>

using namespace std;

struct ROBOT {
	int y, x, dir;
};
ROBOT robo;
int n, m;
int r, c, d;

int map[50][50];
int dy[4] = { -1 , 0 , 1 , 0 };
int dx[4] = { 0 , 1 , 0 , -1 };

int main()
{
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> map[i][j];
		}
	}
	robo.y = r, robo.x = c, robo.dir = d;
	queue<ROBOT> q;
	q.push(robo);

	int cnt = 0;
	while (!q.empty())
	{
		ROBOT cur = q.front(); q.pop();

		if (map[cur.y][cur.x] == 0)
		{
			map[cur.y][cur.x] = 2;
			cnt++;
		}


		for (int dir = 0; dir < 4; dir++)
		{
			ROBOT next;
			int i = (cur.dir+3-dir)%4;
			next.y = cur.y + dy[i];
			next.x = cur.x + dx[i];
			next.dir = i;

			if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= m || map[next.y][next.x] !=0) continue;

			
			q.push(next);
			break;
			
		}


		if (q.empty())
		{
			ROBOT next;
			next.dir = cur.dir;
			next.y = cur.y + dy[(next.dir + 2) % 4];
			next.x = cur.x + dx[(next.dir + 2) % 4];
			if (map[next.y][next.x] == 2)
			{
				q.push(next);
			}
		}
	}
	cout << cnt;
	


}