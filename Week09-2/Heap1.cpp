#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	bool check = false;
	priority_queue<int, vector<int>, greater<int> > pq;

	for (int i = 0; i < scoville.size(); i++)
	{
		pq.push(scoville[i]);
	}



	int cnt = 0;
	while (pq.size() >= 1)
	{
		if (pq.top() >= K)
		{
			check = true;    break;
		}
		if (pq.size() == 1) break;
		int not_spicy1 = pq.top(); pq.pop();
		int not_spicy2 = pq.top(); pq.pop();
		int mix = not_spicy1 + (not_spicy2 * 2);
		pq.push(mix);


		cnt++;

	}
	if (check) answer = cnt;
	else answer = -1;
	return answer;
}