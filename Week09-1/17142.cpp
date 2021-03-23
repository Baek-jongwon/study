#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int map[50][50];
bool pick[10];
vector<pair<int, int> > v;
int vsize;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int minn = 987654321;
int empty_cnt;

int cnt;
int bfs()
{
	int e_cnt = empty_cnt;
	int visited[50][50] = { 0, };
	queue<pair<int, pair<int, int> > > q;
	for (int i = 0; i < vsize; i++)
	{
		if (pick[i])
		{
			q.push({ 0 ,{v[i].first,v[i].second} });
			visited[v[i].first][v[i].second] = 1;
		}
	}

	while (!q.empty())
	{
		int y = q.front().second.first;
		int x = q.front().second.second;
		int time = q.front().first;
		q.pop();
		if (map[y][x] == 0)
		{
			e_cnt--;
		}
		if (e_cnt == 0)
		{
			return time;
		}

		for (int i = 0; i < 4; i++)
		{
			int next_y = y + dy[i];
			int next_x = x + dx[i];

			if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= n) continue;

			if (map[next_y][next_x] != 1 && !visited[next_y][next_x])
			{
				q.push({ time + 1, {next_y,next_x} });
				visited[next_y][next_x] = 1;

			}

		}
	}
	return 987654321;




}

void dfs(int idx, int count)
{

	if (count == m)
	{

		int min_time = bfs();
		if (min_time != 987654321)
		{
			minn = min_time < minn ? min_time : minn;
		}

		return;
	}

	for (int i = idx; i < vsize; i++)
	{
		if (pick[i]) continue;
		pick[i] = true;
		dfs(i, count + 1);
		pick[i] = false;
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int num;
			cin >> num;
			map[i][j] = num;
			if (num == 2) v.push_back({ i,j });
			if (num == 0) empty_cnt++;
		}
	}
	vsize = v.size();

	dfs(0, 0);

	if (minn == 987654321)
	{
		cout << -1;
	}
	else cout << minn;


}