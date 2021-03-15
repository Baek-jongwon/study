#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 1001;
const int INF = 987654321;
int N, M, X , s , e , t;
vector<pair<int, int > > v[MAX];
vector<int> party_d;
vector<int> dist;


void dijkstra(int start , vector<int> &d)
{
	d.assign(N + 1, INF);
	d[start] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		int dist = -pq.top().first;
		int home = pq.top().second;
		pq.pop();

		if (dist > d[home]) continue;
		for (int i = 0; i < v[home].size(); i++)
		{
			int nextdist = dist + v[home][i].second;
			int nexthome = v[home][i].first;

			if (nextdist < d[nexthome])
			{
				d[nexthome] = nextdist;
				pq.push({-nextdist , nexthome});
			}
		}
	}
}


int main()
{
	cin >> N >> M >> X;

	for (int i = 0; i < M; i++)
	{
		cin >> s >> e >> t;
		v[s].push_back({ e,t });
	}
	
	dijkstra(X, party_d);

	
	int maxx = 0;
	for (int i = 1; i <= N; i++)
	{
		dist.clear();
		if (i == X) continue;
		dijkstra(i, dist);
		

		int total_dist = party_d[i] + dist[X];
		maxx = maxx < total_dist ? total_dist: maxx;
	}
	cout << maxx;
	
}