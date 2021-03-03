#include <iostream>
#include <algorithm>

using namespace std;

int n, k, d, mid, rule[10000][3];

bool check()
{
	long long cnt = 0;
	for (int i = 0; i < k; i++)
	{
		if (mid >= rule[i][0])
		{
			cnt += (min(mid, rule[i][1])-rule[i][0])/rule[i][2]+1;
		}
	}
	return cnt >= d;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k >> d;

	for (int i = 0; i < k; i++)
	{
		cin >> rule[i][0] >> rule[i][1] >> rule[i][2];
	}


	int l = 1, r = 1000000;

	while (l <= r)
	{
		mid = (l + r) / 2;

		if (check())
		{
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << l;

}