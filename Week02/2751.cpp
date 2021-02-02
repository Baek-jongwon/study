#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	vector<int> v;

	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v[i] = num;
	}

	sort(v.begin(), v.end());
	for (int j = 0; j < v.size(); j++)
	{
		cout << v[j] << "\n";
	}
	
	

}