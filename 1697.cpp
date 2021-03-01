#include <iostream>
#include <queue>

#define MAX 100001
using namespace std;

int n, k;
int length[100001];
bool visited[100001];
void bfs(int a, int b)
{
	queue<int> q;
	q.push(a);
	visited[a] = true;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		
		if (x == b)
		{
			break;
		}
		if (x+1 < MAX &&!visited[x+1])
		{
			q.push(x + 1);
			length[x + 1] = length[x] + 1;
			visited[x + 1] = true;
		}
		if (2 * x < MAX && !visited[x*2])
		{
			q.push(x * 2);
			length[x * 2] = length[x] + 1 ;
			visited[x*2] = true;
		}

		if (x - 1>= 0 && !visited[x-1]) 
		{
			q.push(x - 1);
			length[x - 1] = length[x] + 1;
			visited[x - 1] = true;
		}
	}

}


int main()
{
	cin >> n >> k;

	if (n - k > 0)
	{
		cout << n - k;
		return 0;
	}

	bfs(n, k);
	cout << length[k];
}