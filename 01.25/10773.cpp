#include <iostream>
#include <stack>


using namespace std;

int main()
{
	int n;
	int num;
	int total = 0;
	stack<int> s;

	cin >> n;
	
	while (n--)
	{
		cin >> num;
		if (num != 0)
		{
			s.push(num);
			total += num;
		}
		else
		{
			total -= s.top();
			s.pop();
		}
	}
	cout << total;
}