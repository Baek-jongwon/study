#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	int size = progresses.size();
	bool check[size];
	for (int i = 0; i < size; i++)
	{
		check[i] = false;
	}
	queue<int> q;
	int start = 0;
	while (q.size() != size)
	{
		int cnt = 0;
		for (int i = 0; i < size; i++)
		{
			if (progresses[i] >= 100) continue;
			progresses[i] += speeds[i];
			if (progresses[i] >= 100) check[i] = true;
		}

		for (int i = start; i < size; i++)
		{
			if (check[i]) {
				q.push(i);
				cnt++;
			}
			else {
				start = i; break;
			}
		}
		if (cnt > 0) answer.push_back(cnt);


	}



	return answer;
}