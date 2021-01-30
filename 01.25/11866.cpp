#include <iostream>
#include <queue>


using namespace std;


int main()
{
	int n;
	int k;
	queue<int> q;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}
	cout << "<";
	while (!q.empty())
	{
		for (int j = 0; j < k - 1; j++)
		{
			q.push(q.front());
			q.pop();
		}
		cout << q.front();

		q.pop();
		if (q.empty())
		{
			cout << ">";
		}
		else
		{
			cout << ", ";
		}
	}
}

	
