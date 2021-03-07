#include <iostream>
#include <vector>

#define MAX 1000001
using namespace std;
vector<int> v;

int n;

int mylower_bound(vector<int>::iterator start, int end , int key)
{
	int s = 0;
	int e = end-1;
	while (e>s)
	{
		int mid = (s + e) / 2;
		if (start[mid] < key)
		{
			s = mid + 1;
		}
		else {
			e = mid;
		}
	}


	return e;
}


int main()
{
	cin >> n;
	int maxx = 0;

	int size = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (v.empty() || v.back() < x)
		{
			v.push_back(x);
			size = v.size();
		
		}
		else
		{
			int idx = mylower_bound(v.begin(), size, x);
			v[idx] = x;
		}
		
	}

	cout << v.size();


}
