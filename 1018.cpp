#include <iostream>
#include <string>
using namespace std;

int m, n, cnt_W, cnt_B;
int min_cnt_W=2500, min_cnt_B=2500;
char **chess;
char chess8x8[9][8] = { {'W','B','W','B','W','B','W','B'},
						{'B','W','B','W','B','W','B','W'},
						{'W','B','W','B','W','B','W','B'},
						{'B','W','B','W','B','W','B','W'},
						{'W','B','W','B','W','B','W','B'},
						{'B','W','B','W','B','W','B','W'},
						{'W','B','W','B','W','B','W','B'},
						{'B','W','B','W','B','W','B','W'},
						{'W','B','W','B','W','B','W','B'}
						};

int main()
{
	cin >> m >> n;
	chess = new char*[m];
	for (int i = 0; i < m; i++)
	{
		string str;
		chess[i] = new char[n];
		cin >> str;
		for (int j = 0; j < str.length(); j++)
		{
			chess[i][j] = str[j];
		}
	}

	for (int i = 0; i <= m - 8; i++)
	{
		
		for (int j = 0; j <= n - 8; j++)
		{
			cnt_W = 0;
			cnt_B = 0;
			for (int k = 0; k < 8; k++)
			{
				for (int a = 0; a < 8; a++)
				{
					if (chess[i + k][j + a] != chess8x8[k][a])
					{
						cnt_W++;
					}
					if (chess[i + k][j + a] != chess8x8[k+1][a])
					{
						cnt_B++;
					}
				}
			}
			
			if (min_cnt_W > cnt_W)
			{
				min_cnt_W = cnt_W;
			}
			if (min_cnt_B > cnt_B)
			{
				min_cnt_B = cnt_B;
			}
		}
	}
	if (min_cnt_W < min_cnt_B)
	{
		cout << min_cnt_W;
	}
	else if (min_cnt_B < min_cnt_W)
	{
		cout << min_cnt_B;
	}
	return 0;
	
	
}