#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

queue<int> q;
vector<int> v[1001];
bool visited_d[1001];
bool visited_b[1001];
void dfs(int curr)
{
	cout << curr << " ";
	visited_d[curr] = true;
	for (int i = 0; i < v[curr].size(); i++)
	{
		
		if (!visited_d[v[curr][i]])
		{
			dfs(v[curr][i]);
		}
	}
}

void bfs(int curr)
{
	q.push(curr);
	
	visited_b[curr] = true;
	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		cout << temp << " ";
		for (int i = 0; i < v[temp].size(); i++)
		{
			if (!visited_b[v[temp][i]])
			{
				q.push(v[temp][i]);
				visited_b[v[temp][i]] = true;
			}
		}
	}
	


}


int main()
{
	int n ,m ,V;
	cin >> n >> m >> V;

	for (int i = 0; i < m; i++)
	{
		int p, c;

		cin >> p >> c;
		v[c].push_back(p);
		v[p].push_back(c);
		sort(v[p].begin(), v[p].end());
		sort(v[c].begin(), v[c].end());
	}
	
	dfs(V);
	cout << "\n";
	bfs(V);

}