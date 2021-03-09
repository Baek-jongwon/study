#include <iostream>

#define MAX 1000000000;
using namespace std;

long long dist[100001];
long long cost[100001];

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n - 1; i++)
	{
		cin >> dist[i];
	}
	for (int i = 1; i <= n ; i++)
	{
		cin >> cost[i];
	}

	long long total = 0;
	long long comp = MAX;

	for (int i = 1; i <= n; i++)
	{
		if (cost[i] < comp)
		{
			comp = cost[i];
		}
		total += comp * dist[i];
	}
	cout << total;

}