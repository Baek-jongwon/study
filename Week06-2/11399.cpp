#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int time = v[0];

	for (int i = 1; i < n; i++)
	{
		v[i] = v[i] + v[i - 1];
		time += v[i];
	}
	cout << time;
}