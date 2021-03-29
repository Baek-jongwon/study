#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
	long long answer = 0;
	long long low = 1;
	long long high = (long long)n *(*max_element(times.begin(), times.end()));

	while (low <= high)
	{
		long long mid = (low + high) / 2;
		long long human = 0;
		for (int i = 0; i < times.size(); i++)
		{
			human += mid / times[i];
		}
		if (n <= human)
		{
			answer = mid;
			high = mid - 1;
		}
		else low = mid + 1;


	}


	return answer;
}