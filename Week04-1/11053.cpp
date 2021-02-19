#include <iostream>
#include <algorithm>
using namespace std;

int d[1001] ;
int arr[1001];
int maxx = 0;
int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	
	for (int i = 1; i <= n; i++)
	{
		d[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j] && d[j]+1 > d[i])
			{
				d[i] = d[j] + 1 ;
			}
		}
		if (d[i] > maxx) maxx = d[i];

	}
	cout << maxx << "\n";
	

}
