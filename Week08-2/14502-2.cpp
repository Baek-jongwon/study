#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int N, M,maxx;
int map[8][8];
int dy[4] = { 0 ,0 , -1 , 1 };
int dx[4] = { -1, 1, 0 , 0 };
vector<pair<int, int> > v;

int bfs()
{
	queue<pair<int, int> > q;
	for (int i = 0; i < v.size(); i++)
	{
		q.push({ v[i].first , v[i].second });
	}


	int temp[8][8];
	memcpy(temp, map, sizeof(map));


	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int new_y = y + dy[i];
			int new_x = x + dx[i];

			if(new_y < N && new_y >=0 && new_x < M && new_x >= 0)
			{
				if (!temp[new_y][new_x])
				{
					temp[new_y][new_x] = 2;
					q.push({ new_y,new_x });
				}

			}


		}
	}
	int zero_cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (temp[i][j] == 0) zero_cnt++;
		}
	}
	return zero_cnt;
}


void dfs(int cnt, int sy, int sx)
{
	if (cnt == 3)
	{
		int num = bfs();
		
		maxx = maxx < num ? num : maxx;
		return;
	}
	for (int i = sy; i < N; i++)
	{
		for (int j = sx; j < M; j++)
		{
			if (map[i][j] == 0)
			{
				map[i][j] = 1;
				dfs(cnt + 1, i, j);
				map[i][j] = 0;
			}
		}
		sx = 0;
	}

}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int num;
			cin >> num;
			map[i][j] = num;
			if (num == 2) v.push_back({i,j});
		}
	}

	dfs(0, 0, 0);

	cout << maxx;
}
 
