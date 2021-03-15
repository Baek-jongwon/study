#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int MAX = 101;
const int INF = 987654321;
int N, M;
int miro[MAX][MAX];
int wall[MAX][MAX];
bool v[MAX][MAX];
int dx[4] = { 0 , 1 , -1 , 0 };
int dy[4] = { 1 , 0 , 0 , -1 };

void dijkstra(int n, int m)
{
	v[n][m] = true;
	priority_queue<pair<int, pair<int, int> > > pq;
	pq.push({ 0 ,{n,m} });
	while (!pq.empty())
	{
		int broken = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();/*
		cout << "x : " << x << endl;
		cout << "y : " << y << endl;*/
		wall[x][y] = broken;
		if (x == N && y == M)
		{
			
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int new_n = x + dx[i];
			int new_m = y + dy[i];
			if (new_n > N || new_n <= 0 || new_m > M || new_m <= 0) continue;
			if (v[new_n][new_m]) continue;
			v[new_n][new_m] = true;
			if (miro[new_n][new_m] == 0 || miro[new_n][new_m] == 1)
			{
				if (miro[new_n][new_m] == 1)
				{
					pq.push({-(broken+1), {new_n , new_m} });
				}
				else
				{
					pq.push({ -(broken),{ new_n,new_m } });
				}
			}
		}
	}
}


int main()
{
	//fill(wall[0],wall[MAX], INF);
	cin >> M >> N;
	cin.ignore();
	for (int i = 1; i <= N; i++)
	{
		string s;
		getline(cin, s);

		for (int j = 0; j < s.length(); j++)
		{
			miro[i][j + 1] = s[j] - '0';
		}
	}

	


	dijkstra(1, 1);
	cout << wall[N][M];
	/*for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cout << wall[i][j];
		}
		cout << endl;
	}*/

}