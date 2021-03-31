#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	vector<vector<int>> arr(n + 1, vector<int>(n + 1, 0));

	for (auto r : results) arr[r[0]][r[1]] = 1;
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == j) continue;
				if (arr[i][k] == 1 && arr[k][j] == 1)
				{
					arr[i][j] = 1;
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
			if (arr[i][j] == 1 || arr[j][i] == 1) cnt++;
		}
		if (cnt == n - 1) answer++;
	}





	return answer;
}