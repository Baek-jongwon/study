#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int T, L;
int visited[301][301];
int length[301][301];
int dx[8] = {-2,-1,1,2,2,1,-1,-2};
int dy[8] = {-1,-2,-2,-1,1,2,2,1};

void bfs(int y1, int x1, int y2, int x2)
{
	queue<pair<int,int>> q;
	q.push(make_pair(y1, x1));
	visited[y1][x1]=true;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (y == y2 && x == x2)
		{
			break;
		}
		int new_y, new_x;
		for (int i = 0; i < 8; i++)
		{
			new_y = y + dy[i];
			new_x = x + dx[i];
			if (new_y >= 0 && new_y < L && new_x >= 0 && new_x < L)
			{
				if (!visited[new_y][new_x])
				{
					length[new_y][new_x] = length[y][x] + 1;
					visited[new_y][new_x] = true;
					q.push(make_pair(new_y, new_x));
					
				}
			}
		}
	}
}


int main()
{
	cin >> T;
	
	while (T--)
	{
		cin >> L;

		memset(visited, 0, sizeof(visited));
		memset(length, 0, sizeof(length));
		int s_y, s_x, e_y, e_x;

		cin >> s_y >> s_x >> e_y >> e_x;

		
		bfs(s_y, s_x, e_y, e_x);

		cout <<length[e_y][e_x] << endl;
	}


}