#include <iostream>

using namespace std;

int n, k;
long long length[10001];

bool check(long long m)
{
	long long cnt=0;
	for (int i = 0; i < n; i++)
	{
		cnt += length[i] / m;
	}
	return cnt >= k;
}

int main()
{
	cin >> n >> k;
	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> length[i];
		sum += length[i];
	}

	long long low = 1; 
	long long high = sum / k;
	while (low <= high)
	{

		long long mid = (low + high) / 2; // overflow Á¶½É
		if (check(mid))
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	cout << high;
}