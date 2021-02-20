#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> parent;
vector<int> depth;


void DFS(int curr, int d)
{
	depth[curr] = d;

	for (int i = 0; i < adj[curr].size(); i++)
	{
		int next = adj[curr][i];
		DFS(next, d + 1);
	}
}


int main()
{
	int T,n;

	cin >> T;

	while (T--)
	{
		cin >> n;
		adj.assign(n + 1, vector<int>());
		parent.assign(n + 1, 0);
		depth.assign(n + 1, 0);

		int u, v;
		for (int i = 0; i < n - 1; i++)
		{
			cin >> u >> v;
			adj[u].push_back(v);
			parent[v] = u;
		}

		int root;

		for (int i = 1; i <= n; i++)
		{
			if (!parent[i])
			{
				root = i;
				break;
			}
		}


		DFS(root,0);


		int num1, num2;
		cin >> num1 >> num2;

		while (depth[num1] != depth[num2])
		{
			if (depth[num1] < depth[num2])
			{
				num2 = parent[num2];
			}
			else {
				num1 = parent[num1];
			}
		}


		while (num1 != num2)
		{
			num1 = parent[num1];
			num2 = parent[num2];
		}
		cout << num1 << "\n";


	}

}