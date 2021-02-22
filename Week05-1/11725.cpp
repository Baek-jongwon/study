#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v[100001];
bool visited[100001];
int parent[100001];
int num=2;
void dfs(int curr)
{
	visited[curr] = true;
	
	for (int i = 0; i < v[curr].size(); i++)
	{
		int child = v[curr][i];
		if (!visited[child])
		{
			visited[child] = true;
			parent[child] = curr;
			dfs(child);
		}
	}
}


int main()
{
	
	cin >> n;

	for (int i = 0; i < n-1; i++)
	{
		int p, c;
		cin >> p >> c;
		v[p].push_back(c);
		v[c].push_back(p);
	}
	
	dfs(1);


	for (int i = 2; i <= n; i++)
	{
		cout << parent[i] << "\n";
	}
}