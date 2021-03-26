#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int time = 0;
	int bridge_w = 0;
	int idx = 0;
	queue<int> q;
	queue<int> t;
	while (1)
	{
		time++;
		if (time - t.front() == bridge_length)
		{
			bridge_w -= q.front();
			q.pop();
			t.pop();
		}

		if (bridge_w + truck_weights[idx] <= weight)
		{
			if (idx == truck_weights.size() - 1)
			{
				time += bridge_length;
				break;
			}

			bridge_w += truck_weights[idx];
			q.push(truck_weights[idx]);
			t.push(time);
			idx++;

		}

	}




	return time;
}