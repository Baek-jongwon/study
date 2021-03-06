#include <iostream>
#include <algorithm>
using namespace std;

int coin[101] = { 0, };
int d[10001] = { 0, };


int main()
{
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= k; i++)
	{
		d[i] = 10001;
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> coin[i];
		for (int j = coin[i]; j <= k; j++)
		{
			d[j] = min(d[j], d[j - coin[i]] + 1);
		}
	}
	
	if (d[k] == 10001)
	{
		cout << "-1\n";
	}
	else cout << d[k] << endl;


}