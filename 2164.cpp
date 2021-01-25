#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	int N;
	int cnt;
	queue<int> q;

	cin >> N;

	for (int i = 1; i <= N; i++) 
	{
		q.push(i);
	}

	cnt = q.size();

	while (cnt > 1) 
	{
		q.pop();
		q.push(q.front());
		q.pop();
		cnt -= 1;
	}

	cout << q.front() << endl;

	return 0;
}