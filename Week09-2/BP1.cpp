#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> supo1;
	vector<int> supo2;
	vector<int> supo3;
	for (int i = 0; i < 5; ++i)
		supo1.push_back(i + 1);
	for (int i = 0; i < 8; ++i)
		supo2.push_back(2);
	for (int i = 0; i < 10; ++i)
		supo3.push_back(3);
	supo2[1] = 1;
	supo2[3] = 3;
	supo2[5] = 4;
	supo2[7] = 5;
	supo3[2] = 1;
	supo3[3] = 1;
	supo3[4] = 2;
	supo3[5] = 2;
	supo3[6] = 4;
	supo3[7] = 4;
	supo3[8] = 5;
	supo3[9] = 5;
	int supo1_size = supo1.size();
	int supo2_size = supo2.size();
	int supo3_size = supo3.size();
	int ans_size = answers.size();
	if (ans_size > supo1.size())
	{
		int alpha = ans_size / supo1_size;
		for (int i = 0; i < alpha; i++)
		{
			for (int j = 0; j < supo1_size; j++)
			{
				supo1.push_back(supo1[j]);
			}

		}
	}
	if (ans_size > supo2_size)
	{
		int alpha = ans_size / supo2_size;
		for (int i = 0; i < alpha; i++)
		{
			for (int j = 0; j < supo2_size; j++)
			{
				supo2.push_back(supo2[j]);
			}

		}
	}
	if (ans_size > supo3_size)
	{
		int alpha = ans_size / supo3_size;
		for (int i = 0; i < alpha; i++)
		{
			for (int j = 0; j < supo3_size; j++)
			{
				supo3.push_back(supo3[j]);
			}
		}
	}

	pair<int, int> cnt1;
	pair<int, int> cnt2;
	pair<int, int> cnt3;
	cnt1.second = 1;
	cnt2.second = 2;
	cnt3.second = 3;

	vector<pair<int, int> > cnt;
	for (int i = 0; i < ans_size; i++)
	{
		if (supo1[i] == answers[i]) cnt1.first++;
		if (supo2[i] == answers[i]) cnt2.first++;
		if (supo3[i] == answers[i]) cnt3.first++;
		if (i == ans_size - 1) {
			cnt.push_back(cnt1);
			cnt.push_back(cnt2);
			cnt.push_back(cnt3);
		}
	}

	sort(cnt.begin(), cnt.end(), greater<pair<int, int> >());

	if (cnt[0].first == cnt[1].first) {
		if (cnt[0].first == cnt[1].first && cnt[1].first == cnt[2].first)
		{
			answer.push_back(cnt[2].second);
			answer.push_back(cnt[1].second);
			answer.push_back(cnt[0].second);
		}
		else {
			answer.push_back(cnt[1].second);
			answer.push_back(cnt[0].second);
		}

	}
	else answer.push_back(cnt[0].second);






	return answer;
}