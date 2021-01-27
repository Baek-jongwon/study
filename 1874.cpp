#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;


int main()
{
	
	
	int num;
	int cnt;
	int max = 0;
	stack<int> s;
	queue<int> q;
	vector <char> plma;
	cin >> cnt;

	while (cnt--)
	{
		cin >> num;
		if (num > max)
		{
			for (int i = max + 1; i <= num; i++)
			{
				s.push(i);
				plma.push_back('+');
			}
		}
		else
		{
			if (s.top() != num)
			{
				cout << "NO\n";
				return 0;
			}
		}
		s.pop();
		plma.push_back('-');
		if (max < num) max = num;
		
	}
	
	for (int i = 0; i < plma.size(); i++)
	{
		cout << plma[i] <<"\n";
	}
	return 0;

}
