#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1001;
const int INF = 987654321;

vector<pair<int, int> > v[MAX];
int d[MAX];
int N, M, A, B;

int dijkstra(int start, int end)
{
	fill_n(d , N + 1, INF);
	d[start] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push({ 0,start });

	while (!pq.empty())
	{
		int dist = -pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (dist > d[node]) continue;
		for (int i = 0; i < v[node].size(); i++)
		{
			int nextdist = dist + v[node][i].second;
			int nextnode = v[node][i].first;

			if (nextdist < d[nextnode])
			{
				d[nextnode] = nextdist;
				pq.push({ -nextdist, nextnode });
			}

		}


	}
	return d[end];
}


int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });

	}
	cin >> A >> B;
	int min_cost = dijkstra(A, B);
	cout << min_cost;

}
