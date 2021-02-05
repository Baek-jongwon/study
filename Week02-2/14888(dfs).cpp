#include <iostream>

using namespace std;

int n;
int result_max = -1000000001;
int result_min = 1000000001;
int num[11];
int op[4];

void dfs(int number, int idx)
{
	if (idx == n - 1)
	{
		if (number > result_max)
		{
			result_max = number;
		}
		if (number < result_min)
		{
			result_min = number;
		}
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (op[i] > 0)
		{
			op[i]--;
			if (i == 0)
			{
				dfs(number + num[idx + 1], idx + 1);
			}
			else if (i == 1)
			{
				dfs(number - num[idx + 1], idx + 1);
			}
			else if (i == 2)
			{
				dfs(number * num[idx + 1], idx + 1);
			}
			else if (i == 3)
			{
				dfs(number / num[idx + 1], idx + 1);
			}
			op[i]++;
		}
	}
}



int main() {

	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	for (int j = 0; j < 4; j++)
	{
		cin >> op[j];
	}
	dfs(num[0], 0);
	cout << result_max << "\n";
	cout << result_min;

}