#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;

bool compare(pair<int, int>& a, pair<int, int>& b)
{
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}
int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(), compare);

	int s = v[0].first;
	int e = v[0].second;
	int cnt = 1;
	for (int i = 1; i < n; i++)
	{
		if (e <= v[i].first)
		{
			e = v[i].second;
			cnt++;
		}
	}
	cout << cnt;
}