#include <iostream>

#define MAX 301
using namespace std;

int arr[MAX];
int d[MAX];

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
	}
	d[1] = arr[1];
	d[2] = arr[1] + arr[2];
	d[3] = max(d[1] + arr[3], arr[2]+arr[3]);

	for (int j = 4; j <= n; j++)
	{
		d[j] = max(d[j - 2] + arr[j], d[j - 3] + arr[j - 1] + arr[j]);
	}

	cout << d[n] << "\n";
}