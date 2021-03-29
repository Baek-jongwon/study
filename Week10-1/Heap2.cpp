#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

struct comp {
	bool operator()(vector<int> a, vector<int> b)
	{
		return a.at(1) > b.at(1);
	}
};

int solution(vector<vector<int>> jobs) {
	int answer = 0;
	sort(jobs.begin(), jobs.end());
	priority_queue<vector<int>, vector<vector<int>>, comp> pq;
	int size = jobs.size();
	int idx = 0, start_time = 0;
	while (idx < size || !pq.empty())
	{
		if (idx < size && start_time >= jobs[idx][0])
		{
			pq.push(jobs[idx++]);
			continue;
		}

		if (!pq.empty())
		{
			start_time += pq.top()[1];
			answer += start_time - pq.top()[0];
			pq.pop();
		}
		else {
			start_time = jobs[idx][0];
		}


	}



	return answer / size;
}