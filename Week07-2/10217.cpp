#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);

	for (int turn = 1; turn <= T; turn++) {
		int n, m, t;
		scanf("%d %d %d", &n, &m, &t);
		int s, g, h;
		scanf("%d %d %d", &s, &g, &h);

		vector<pair<int, int>> city[2001];
		pair<int, bool> d[2001];
		vector<int> can(t);
		for (int i = 0; i < 2001; i++) {
			d[i] = { 10e8 * 2,0 };
		}
		for (int i = 0; i < m; i++) {
			int a, b, d;
			scanf("%d %d %d", &a, &b, &d);
			d = d * 2;
			if ((a == g || a == h) && (b == g || b == h)) {
				d--;
			}

			city[a].push_back({ b,d });
			city[b].push_back({ a,d });

		}
		for (int i = 0; i < t; i++) {
			scanf("%d", &can[i]);
		}

		priority_queue<pair<int, int>> pq;
		pq.push({ s,0 });
		d[s].first = 0;
		while (!pq.empty()) {
			int cur = pq.top().first;
			int distance = -pq.top().second;
			pq.pop();

			if (d[cur].first < distance)
				continue;

			for (int i = 0; i < city[cur].size(); i++) {

				int next = city[cur][i].first;

				int ndistance = city[cur][i].second + distance;

				if (ndistance < d[next].first) {
					d[next].first = ndistance;
					pq.push({ next,-ndistance });
				}

			}
		}
		vector<int> ans;
		for (int i = 0; i < can.size(); i++) {
			if (d[can[i]].first % 2 == 1)
				ans.push_back(can[i]);
		}

		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	return 0;
}

