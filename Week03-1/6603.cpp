#include <iostream>

#define R 6

using namespace std;
int n;
int *arr;
int lotto[R] = { 0, };

void combination(int depth, int next)
{
	if (depth == R)
	{
		for (int i = 0; i < R; i++)
		{
			cout << lotto[i] << " ";
		}
		cout << "\n";
		
		return;
	}
	for (int j = next; j < n; j++)
	{
		lotto[depth] = arr[j];
		combination(depth + 1, j + 1);
	}
}




int main()
{
	while (1)
	{
		cin >> n;
		

		if (n == 0)
		{
			return 0;
		}
		else
		{
			arr = new int[n];
			for (int i = 0; i < n; i++)
			{
				cin >> arr[i];
			}
			combination(0, 0);
			cout << "\n";

		}

	}
	
}
