#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	vector<pair<int, int> > y_x;
	answer.resize(2);
	for (int i = 1; i <= yellow / 2 + 1; i++)
	{
		if (yellow%i == 0)
		{
			int first = yellow / i;
			if (first >= i)
			{
				y_x.push_back({ first,i });
				cout << " 가로 : " << first << "  세로 : " << i << endl;
			}

		}
	}
	for (int i = 0; i < y_x.size(); i++)
	{
		int x = y_x[i].first;
		int y = y_x[i].second;

		if ((x + 2)*(y + 2) == brown + yellow) {
			answer[0] = x + 2;
			answer[1] = y + 2;
		}
	}
	return answer;
}