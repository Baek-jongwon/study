#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int solution(int distance, vector<int> rocks, int n) {
	int answer = 0;
	vector<int> minmax;
	sort(rocks.begin(), rocks.end());
	for (int i = 0; i < rocks.size(); i++)
	{
		if (i == 0) minmax.push_back(rocks[i]);
		else minmax.push_back(rocks[i] - rocks[i - 1]);
	}
	minmax.push_back(distance - rocks[rocks.size() - 1]);

	int low = *min_element(minmax.begin(), minmax.end());
	int high = *max_element(minmax.begin(), minmax.end());


	while (low <= high)
	{

		int mid = (low + high) / 2;
		int cnt = 0;
		cout << "l : " << low << "  m : " << mid << "  h : " << high << endl;
		int prev = 0;
		for (int i = 0; i < minmax.size(); i++)
		{
			if (minmax[i] + prev < mid) {
				cnt++;
				prev += minmax[i];
			}
			else {
				prev = 0;
			}
		}


		if (cnt > n)
		{
			high = mid - 1;
		}
		else {

			low = mid + 1;
			answer = mid;
		}

	}
	return answer;
}