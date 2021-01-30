# include <iostream>
# include <queue>
# include <string>
using namespace std;

int main()
{
	int n;
	string str;
	queue<char> q;

	cin >> n;
	
	while (n--)
	{
		int front = 0;
		int back = 0;
		int cnt = 0;
		cin >> str;
		for (int i = 0; i < str.length(); i++)
		{
			q.push(str[i]);
		}
		while (!q.empty())
		{
			if (q.front() == '(')
			{
				front++;
			}
			else if (q.front() == ')')
			{
				back++;
			}
			q.pop();
			if (front < back)
			{
				cnt++;
			}
		}
		if (front != back)
		{
			cout << "NO\n";
		}
		else
		{
			if (cnt > 0)
			{
				cout << "NO\n";
			}
			else
			{
				cout << "YES\n";
			}
		}
	}
}
