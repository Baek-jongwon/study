#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[100001];


void check(int size , int num)
{
	int l, r, mid;
	l = 0;
	r = size-1;

	while (l <= r)
	{
		mid = (l + r) % 2 == 1 ? (l + r) / 2 + 1 : (l + r) / 2;
		
		if (num > arr[mid])
		{
			l = mid + 1;
		}
		else if (num < arr[mid])
		{
			r = mid - 1;
		}
		else
		{
			if (num == arr[mid])
			{
				cout << 1 << "\n";
				return;
			}
		}
	}cout << 0 << "\n";
	
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,num;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		
	}
	sort(arr, arr+n);
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int num_;
		cin >> num_;
		check(n,num_);
	}
}