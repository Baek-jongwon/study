#include <iostream>


using namespace std;

int n;
int arr[1001];
int d[1001];
int d_[1001];




int main()
{
	int maxx = 0;
	int maxx_ = 0;
	int length = 0;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		arr[i] = num;

		d[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j] && d[j] >= d[i])
			{
				d[i] = d[j] + 1;
			}

			
		}
		if (d[i] > maxx) maxx = d[i];
		
	}


	for (int i = n - 1; i >= 0; i--)
	{
		d_[i] = 1;
		for (int j = n-1; j >= i; j--)
		{
			if (arr[i] > arr[j] && d_[i] <= d_[j])
			{
				d_[i] = d_[j] + 1;
			}
		}
		if (d_[i] > maxx_)
		{
			maxx_ = d_[i];
		}
	}


	for (int i = 0; i < n; i++)
	{
		int sum;
		sum = d[i] + d_[i];

		if (sum > length) length = sum;
		
	}
	
	cout << length-1;

	
	

}