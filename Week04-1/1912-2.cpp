#include <iostream>

#define MAX 100001
using namespace std;

int arr[MAX] = { 0, };
int d[MAX] = { 0, };
int temp;
int maxx;

int max(int a, int b)
{
	if (a > b) return a; return b;
}
int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		d[i] = arr[i];
	}
	maxx = d[1];
	for (int i = 2; i <= n; i++)
	{
		d[i] = max(d[i], d[i] + d[i - 1]);

		if (d[i] > maxx) maxx = d[i];
	}
	cout << maxx << "\n";
}
