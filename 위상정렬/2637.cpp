#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int result[101][101];
bool check[101];
int indegree[101];
vector<pair<int, int> > v[101];
int n, m , x ,y ,k;


void topologySort()
{
	queue<int>  q;
	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0) {
			q.push(i);
			check[i] = true;
			result[i][i] = 1;
		}
	}

	while (!q.empty()) {

		int curr = q.front();
		
		q.pop();
		for (int i = 0; i < v[curr].size(); i++) {
			int next = v[curr][i].first;
			int cost = v[curr][i].second;
			for (int j = 1; j <= n; j++) result[next][j] += result[curr][j] * cost;
			
			if (--indegree[next] == 0) {
				q.push(next);
			}

		}

	}

}



int main()
{
	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> k;
		v[y].push_back({ x,k });
		indegree[x]++;
	}

	topologySort();
	
	for (int i = 1; i <= n; i++)
	{
		if (check[i]) {
			cout << i << " " <<result[n][i] << endl;
		}
	}


}