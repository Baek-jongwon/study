#include <iostream>

#define MAX 1000001
using namespace std;

int n;
int d[MAX];

int min(int a, int b) 
{
	if (a < b) return a; return b;
}

int main()
{
	cin >> n;

	d[1] = 0;

	for (int i = 2; i <= n; i++)
	{
		d[i] = d[i - 1] + 1;
		
		if (i % 2 == 0)
		{
			d[i] = min(d[i], d[i / 2] + 1);
		}
		if (i % 3 == 0)
		{
			d[i] = min(d[i], d[i / 3] + 1);
		}
	}
	cout << d[n];
	
	

	
}