#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k, x, l;
int board[102][102];
vector<pair<int, int> > apple;
vector<pair<int, char> > dir;

int dy[4] = { -1 , 0 , 1 , 0 };
int dx[4] = { 0 , 1 ,0 ,-1 };
bool snake[101][101];

void dummy(int y, int x)
{
	int count = 0;
	int direction = 1;
	queue<pair<int, int> >  q;
	queue<pair<int, int> > tail;
	q.push({ y,x });
	tail.push({y,x});
	snake[y][x] = true;
	while (!q.empty())
	{
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		q.pop();
		
		for (int i = 0; i < l; i++)
		{
			if (count == dir[i].first)
			{
				if (dir[i].second == 'D') direction = (direction + 1) % 4;
				else if(dir[i].second == 'L')direction = (direction + 3) % 4;
			}
		}
		int dir_y = dy[direction];
		int dir_x = dx[direction];
		int next_y = cur_y + dir_y;
		int next_x = cur_x + dir_x;
		if (board[next_y][next_x] == -1 || snake[next_y][next_x])
		{
			count++;
			break;
		}
		
		if (board[next_y][next_x] == 1)
		{
			board[next_y][next_x] = 0;
			tail.push({ next_y,next_x });
			
			snake[next_y][next_x] = true;
			q.push({ next_y,next_x });
			count++;
		}
		else if (board[next_y][next_x] == 0)
		{
			int tail_y = tail.front().first;
			int tail_x = tail.front().second;
			tail.pop();
			tail.push({ next_y,next_x });
			snake[tail_y][tail_x] = false;
			snake[next_y][next_x] = true;
			q.push({ next_y,next_x });
			count++;
		}
		

	}
	cout << count;
}

int main()
{
	cin >> n >> k;

	for (int i = 0; i <= n + 1; i++)
	{
		board[0][i] = -1;
		board[n+1][i] = -1;
		board[i][0] = -1;
		board[i][n+1] = -1;
	}

	
	for (int i = 0; i < k; ++i)
	{
		int y, x;
		cin >> y >> x;
		apple.push_back({y,x});
		
		board[y][x] = 1;
	}

	cin >> l;
	for (int i = 0; i < l; i++)
	{
		int time;
		char direction;
		cin >> time >> direction;
		dir.push_back({time,direction});
	}

	
	dummy(1,1);

}

