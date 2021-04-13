#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[32001];
int indegree[32001];
int n, m;


void topologySort() {
	vector<int> result;
	queue<int> q;


	for (int i = 1; i <= n; i++) {

		if (indegree[i] == 0) {
			q.push(i);
			result.push_back(i);
		}
	}

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int i = 0; i < v[curr].size(); i++) {
			int next = v[curr][i];

			if (--indegree[next] == 0) {
				q.push(next);
				result.push_back(next);
			}
		}
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
}

int main()
{
	cin >> n >> m;
	
	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		indegree[b]++;
	}


	topologySort();




}
