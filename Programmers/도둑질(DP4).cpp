#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {

	vector<long> d1;
	vector<long> d2;
	d1.assign(money.size(), money[0]);
	d2.assign(money.size(), money[1]);
	d2[0] = 0;
	for (int i = 2; i <= money.size() - 2; i++)
	{
		d1[i] = max(d1[i - 2] + money[i], d1[i - 1]);
	}
	for (int j = 2; j <= money.size() - 1; j++)
	{
		d2[j] = max(d2[j - 2] + money[j], d2[j - 1]);
	}


	return max(d1[money.size() - 2], d2[money.size() - 1]);
}