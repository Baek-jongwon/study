#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int>::iterator iter;

int n, k , cnt;
vector<int> v, p;


int main()
{
	cin >> n >> k;

	for (int i = 0; i < k; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	for (iter it = v.begin(); it != v.end(); ++it)
	{
		if (find(p.begin(), p.end(), *it) != p.end()) continue;

		if (p.size() < n)
		{
			p.push_back(*it);
			continue;
		}

		iter last = it , p_idx = p.begin();
		for (iter p_check = p.begin(); p_check != p.end(); ++p_check)
		{
			iter temp = find(it + 1, v.end(), *p_check);

			if (temp > last)
			{
				p_idx = p_check;
				last = temp;
			}
		}
		*p_idx = *it;
		cnt++;


	}
	cout << cnt;
}