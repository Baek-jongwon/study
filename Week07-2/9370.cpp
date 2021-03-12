#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int T, n, m, t, s, g, h, a, b, c;
const int INF = 987654321;
const int MAX = 2001;
vector<pair<int, int> > v[MAX];
int d_s[MAX];
int d_g[MAX];
int d_h[MAX];


void dijkstra(int start, int d[MAX])
{
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
				pq.push({ -nextdist , nextnode });
			}
		}

	}

}

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> n >> m >> t;
		cin >> s >> g >> h;
		for (int i = 0; i < MAX; i++)
		{
			v[i].clear();
			d_s[i] = INF;
			d_g[i] = INF;
			d_h[i] = INF;
		}
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b >> c;
			v[a].push_back({ b,c });
			v[b].push_back({ a,c });

		}
		vector<int> destination;
		for (int i = 0; i < t; i++)
		{
			int a;
			cin >> a;
			destination.push_back(a);
		}
		dijkstra(s, d_s);
		dijkstra(g, d_g);
		dijkstra(h, d_h);

		sort(destination.begin(), destination.end());
		for (int i = 0; i < t; i++)
		{
			int dest = destination[i];

			if (d_s[dest] == d_s[g] + d_g[h] + d_h[dest]) cout << dest << " ";
			else if (d_s[dest] == d_s[h] + d_h[g] + d_g[dest]) cout << dest << " ";
		}
		cout << "\n";




	}



}