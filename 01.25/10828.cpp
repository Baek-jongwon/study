#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	int n;
	int num;
	string str;
	stack<int> s;
	
	cin >> n;
	
	while (n--)
	{
		cin >> str;
	
		if (str == "push")
		{
			cin >> num;
			s.push(num);
		}
		else if (str == "top")
		{
			if (s.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << s.top() << "\n";
			}
		}
		else if (str == "size")
		{
			cout << s.size() << "\n";
		}
		else if (str == "empty")
		{
			if (s.empty())
			{
				cout << "1\n";
			}
			else
			{
				cout << "0\n";
			}
		}
		else if (str == "pop")
		{
			if (s.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << s.top() << "\n";
				s.pop();
			}
		}
	}
}