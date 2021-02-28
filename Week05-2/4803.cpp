#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> v[501];
bool visited[501];
int n, m;
int tree;
bool dfs(int curr , int before)
{
	visited[curr] = true;

	for (int i = 0; i < v[curr].size(); i++)
	{
		int y = v[curr][i];
		if (y == before) continue;
		if (visited[y]) return false;
		
		if (!dfs(y, curr)) return false;
		
	}
	return true;
	
}


int main()
{
	int cnt= 1;

	
	while (1)
	{
		cin >> n >> m;
		if (n == 0 & m == 0) break;

		int tree = 0;
		memset(visited, false, sizeof(visited));
		for (int i = 1; i <= n; i++)
		{
			v[i].clear();
		}


		
		for (int i = 0; i < m; i++)
		{
			int p, c;
			cin >> p >> c;

			v[p].push_back(c);
			v[c].push_back(p);
		}
		
		
		for (int i = 1; i <= n; i++)
		{
			if (!visited[i])
			{
				if (dfs(i,0))
				{
					tree++;
				}
			}
			
		}
		cout << "Case " << cnt << ": ";
		if (tree == 1)
		{
			cout << "There is one tree.\n";
		}
		else if (tree > 1)
		{
			cout << "A forest of " << tree << " trees.\n";
		}
		else cout<<"No trees.\n";
		
		

		cnt++;
		

	}
	
	

}