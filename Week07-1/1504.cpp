#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int MAX = 1000000000;
int n, e, node1, node2;
vector<pair<int, int> > v[801];

int dijkstra(int start, int end) {
	int d[801];
	fill(d, d + n+1, MAX);
	priority_queue<pair<int,int >> pq;
	pq.push(make_pair(0, start));
	d[start] = 0;

	while (!pq.empty())
	{
		int dist = -pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (dist > d[node]) continue;
		for (int i = 0; i < v[node].size(); i++)
		{
			int nextdist = dist + v[node][i].first;
			int nextnode = v[node][i].second;

			if (nextdist < d[nextnode])
			{
				d[nextnode] = nextdist;
				pq.push(make_pair(-nextdist, nextnode));
			}
		}
	}
	return d[end];
}

int main()
{
	cin >> n >> e;

	for (int i = 1; i <= e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(make_pair(c,b));
		v[b].push_back(make_pair(c,a));
		
	}
	cin >> node1 >> node2;
	
	int s_n1 = dijkstra(1, node1);
	int n1_n2 = dijkstra(node1, node2);
	int n2_N = dijkstra(node2, n);
	bool path1 = true;
	if (s_n1 == MAX || n1_n2 == MAX || n2_N) path1 = false;

	int s_n2 = dijkstra(1, node2);
	int n1_N = dijkstra(node1, n);
	bool path2 = true;
	if (s_n2 == MAX || n1_n2 == MAX || n1_N == MAX) path2 = false;

	if (!path1 && !path2) cout << -1;
	else cout << min(s_n1 + n1_n2 + n2_N, s_n2 + n1_n2 + n1_N);
	
	return 0;


}