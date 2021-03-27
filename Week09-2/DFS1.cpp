#include <string>
#include <vector>
#include <iostream>
using namespace std;

int ret;
int num_size;
bool check[20];
int cal(int t, vector<int> arr)
{
	int total = 0;
	for (int i = 0; i < num_size; i++)
	{
		if (check[i])
		{
			total -= arr[i];
		}
		else total += arr[i];
	}
	int cnt = 0;
	if (total == t) cnt = 1;
	return cnt;
}


void comb(int idx, int count, int t, int tar, vector<int> v)
{
	if (count == t)
	{
		ret += cal(tar, v);
		//to do something
		return;
	}

	for (int i = idx; i < num_size; i++)
	{
		check[i] = true;
		comb(i + 1, count + 1, t, tar, v);
		check[i] = false;
	}
}

int solution(vector<int> numbers, int target) {
	int answer = 0;
	int total = 0;
	num_size = numbers.size();
	for (int i = 0; i <= num_size; i++)
	{
		ret = 0;
		comb(0, 0, i, target, numbers);
		if (ret > 0) total += ret;
	}

	answer = total;

	return answer;
}