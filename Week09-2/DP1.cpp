#include <string>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int base_num(int n, int cnt)
{
	int ret = 0;
	while (cnt > 0)
	{
		cnt--;
		ret += n * pow(10, cnt);
	}
	return ret;
}

int solution(int N, int number) {
	int answer = 0;

	if (N == number)
	{
		return 1;
	}
	answer = -1;
	const int MIN = 8;
	vector<set<int> > v(MIN);

	int idx = 1;
	for (int i = 0; i < MIN; i++)
	{
		v[i].insert(base_num(N, idx));
		idx++;
	}

	for (int i = 1; i < MIN; i++)
	{
		for (int j = 0; j < i; j++)
		{
			for (auto &x1 : v[j])
			{
				for (auto &x2 : v[i - 1 - j])
				{
					v[i].insert(x1 + x2);
					v[i].insert(x1 - x2);
					v[i].insert(x1*x2);
					if (x2 != 0)
					{
						v[i].insert(x1 / x2);
					}
				}
			}
		}
		if (v[i].find(number) != v[i].end())
		{
			answer = i + 1;
			break;
		}
	}


	return answer;
}