#include <iostream>

using namespace std;

int main()
{
	int n, k;

	cin >> n >> k;

	int l = 1;
	int r = k;
	int result = 0;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			cnt += min(mid / i, n);
		}

		if (cnt < k)
		{
			l = mid + 1;
		}
		else
		{
			result = mid;
			r = mid - 1;
		}
	}
	cout << result;



}