#include <iostream>

using namespace std;

int n, num;
int zero_cnt[41] = {1,0,};
int one_cnt[41] = {0,1,};
int main()
{
	cin >> n;
	for (int i = 2; i < 41; i++)
	{
		zero_cnt[i] = zero_cnt[i - 1] + zero_cnt[i - 2];
		one_cnt[i] = one_cnt[i - 1] + one_cnt[i - 2];
		
	}
	while (n--)
	{
		cin >> num;
		cout << zero_cnt[num] << " " << one_cnt[num] << "\n";	
	}

}