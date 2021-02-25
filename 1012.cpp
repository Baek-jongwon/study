#include <iostream>


using namespace std;

bool visited[51][51];

int T , M , N , K;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };



void dfs(int y, int x)
{
	visited[y][x] = false;
	int new_y, new_x;
	for (int i = 0; i < 4; i++)
	{
		new_y = y + dy[i];
		new_x = x + dx[i];
		
		if (new_x > 0 && new_x <= M && new_y > 0 && new_y <= N)
		{
			if (visited[new_y][new_x])
			{
				dfs(new_y, new_x);
			}
		}
	}
}



int main()
{
	int cnt;
	cin >> T;

	while (T--)
	{
		cin >> M >> N >> K;
		cnt = 0;
		for (int i = 0; i < K; i++)
		{
			int x, y;
			cin >> x >> y;
			visited[y + 1][x + 1] = true;
			
		}

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (visited[i][j])
				{
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}



}