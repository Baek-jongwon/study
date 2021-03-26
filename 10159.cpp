#include <iostream>

using namespace std;


int n, m;
int graph[101][101];
int main()
{
	cin >> n >> m;
	

	for (int i = 0; i < m; i++)
	{
		int y, x;
		cin >> y >> x;
		graph[y][x] = 1;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (graph[i][k] ==1 && graph[k][j] == 1)
				{
					graph[i][j] = 1;
				}
			}
		}
	}


	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			if (graph[i][j] == 0 && graph[j][i] == 0) cnt++;
		}
		cout << cnt <<endl;
	}




}