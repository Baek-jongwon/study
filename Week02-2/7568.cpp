#include <iostream>

using namespace std;

int main()
{
	int n;
	int num = 1;
	pair<int, int> arr[50];
	cin >> n;
	

	for(int i =0; i<n; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i].first < arr[j].first && arr[i].second < arr[j].second)
			{
				num++;
			}
		}
		cout << num << " ";
		num = 1;
	}

}