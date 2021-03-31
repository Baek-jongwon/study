#include <string>
#include <vector>
#include <iostream>
using namespace std;

int d[500][500];
int solution(vector<vector<int>> triangle) {
	int answer = 0;
	int size = triangle.size();

	d[0][0] = triangle[0][0];
	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0) d[i][j] = d[i - 1][j] + triangle[i][j];
			else if (j == i) d[i][j] = d[i - 1][j - 1] + triangle[i][j];
			else {
				d[i][j] = max(d[i - 1][j], d[i - 1][j - 1]) + triangle[i][j];
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		answer = answer < d[size - 1][i] ? d[size - 1][i] : answer;
	}





	return answer;
}