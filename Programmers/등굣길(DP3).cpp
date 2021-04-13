#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;
	int map[101][101];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			map[i][j] = 1;
		}
	}
	for (int i = 0; i < puddles.size(); i++) {
		int y = puddles[i][1];
		int x = puddles[i][0];

		map[y][x] = 0;

		if (x == 1) {
			for (int j = y; j <= n; j++)
				map[j][1] = 0;
		}

		if (y == 1) {
			for (int j = x; j <= m; j++)
				map[1][j] = 0;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; j <= m; j++)
		{
			if (map[i][j] == 0) continue;
			map[i][j] = (map[i - 1][j] + map[i][j - 1]) % 1000000007;
		}
	}
	answer = map[n][m];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	return answer;
}