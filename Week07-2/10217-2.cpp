#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 101;
const int INF = 987654321;
int T, N, M, K, a, b, c, d;

vector<pair<int, pair<int, int> > > v[MAX];
int dp[MAX][10001];


void dijkstra(int start)
{
	priority_queue<pair<int, pair<int, int> > > pq;
	dp[start][0] = 0;

	pq.push({ 0 ,{start,0} });

	while (!pq.empty())
	{
		int time = -pq.top().first;
		int node = pq.top().second.first;
		int cost = pq.top().second.second;

		pq.pop();
		for (int i = 0; i < v[node].size(); i++)
		{
			int nexttime = time + v[node][i].second.second;
			int nextnode = v[node][i].first;
			int nextcost = cost + v[node][i].second.first;
			if (nextcost > M) continue;

			if (nexttime < dp[nextnode][nextcost])
			{
				dp[nextnode][nextcost] = nexttime;
				pq.push({ -nexttime,{nextnode ,nextcost} });
			}
		}

	}
}

int main()
{
	cin >> T;

	while (T--)
	{
		for (int i = 0; i < MAX; i++)
		{
			v[i].clear();
			for (int j = 0; j < 10001; j++)
			{
				dp[i][j] = INF;
			}
		}
		cin >> N >> M >> K;
		for (int i = 0; i < K; i++)
		{
			cin >> a >> b >> c >> d;
			v[a].push_back({ b, {c,d} });
		}

		dijkstra(1);
		int minn = INF;
		for (int i = 0; i <= M; i++)
		{
			minn = min(minn, dp[N][i]);
		}
		if (minn != INF) cout << minn << "\n";
		else cout << "Poor KCM\n";

	}

}