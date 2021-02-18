#include <iostream>
#include <algorithm>

using namespace std;

int d[101][100001];

struct Thing {
	int w, v;
};

Thing things[101];
int main()
{
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> things[i].w >> things[i].v;
	}

	for (int i = 1; i <= n; i++)
	{
		int wi = things[i].w;
		int vi = things[i].v;
		for (int j = 1; j <= k; j++)
		{
			if (wi > j)
			{
				d[i][j] = d[i - 1][j];
			}
			else {
				d[i][j] = max(d[i - 1][j], vi + d[i - 1][j - wi]);
			}
		}
	}
	cout << d[n][k];
	
	
}