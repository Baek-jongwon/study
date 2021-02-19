#include <iostream>
#include <vector>

using namespace std;

vector<int> v[51];
int r;
int DFS(int curr)
{
	int child = 0;

	for (auto node : v[curr])
	{
		if (node == r)
		{
			continue;
		}
		child += DFS(node);
	}

	if (child) return child;
	else return 1;
}

int main()
{
	int n, root;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int p;
		cin >> p;

		if (p == -1) root = i;
		else {
			v[p].push_back(i);
		}
	}

	cin >> r;
	
	if (r != root)
	{
		cout <<DFS(root) <<"\n";
	}
	else cout << 0 << "\n";
}