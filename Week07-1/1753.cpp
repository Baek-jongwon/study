#include <iostream>
#include <vector>
#include <queue>

#define MAX 1000000000
using namespace std;

int V, E;
vector<pair<int, int> > p[20001];
int d[20001];

void dijkstra(int s)
{
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, s));
	d[s] = 0;
	while (!pq.empty())
	{
		int dist = -pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (dist > d[node]) continue;
		for (int i = 0; i < p[node].size(); i++)
		{
			int nextdist = dist + p[node][i].first;
			int nextnode = p[node][i].second; 
			if (nextdist < d[nextnode])
			{
				d[nextnode] = nextdist;
				pq.push(make_pair(-nextdist, nextnode));
			}
		}
	}

}


int main()
{
	cin >> V >> E;
	int start;
	cin >> start;

	for (int i = 1; i <= E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		p[u].push_back(make_pair(w, v));
	}

	for (int i = 1; i <= V; i++)
	{
		d[i] = MAX;
	}
	dijkstra(start);

	for (int i = 1; i <= V; i++)
	{
		if (d[i] != MAX)
		{
			cout << d[i] << "\n";
		}
		else {
			cout << "INF\n";
		}
	}



}