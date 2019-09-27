#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int C;
vector<vector<pair<int, int>>> adj;
int main() {
	scanf("%d", &C);
	for (int c = 1; c <= C; c++) {
		int V, E, n, m;
		scanf("%d%d%d%d", &V, &E, &n, &m);
		adj.clear();
		adj.resize(V + 1);
		vector<int> dist(V + 1, 987654321);

		while (E--) {
			int a, b, t;
			scanf("%d%d%d", &a, &b, &t);
			adj[a].push_back(make_pair(b, t));
			adj[b].push_back(make_pair(a, t));
		}

		vector<int> fire(n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &fire[i]);
		}

		for (int i = 0; i < m; i++) {
			int firestation;
			scanf("%d", &firestation);

			adj[0].push_back(make_pair(firestation, 0));
			adj[firestation].push_back(make_pair(0, 0));
		}


		priority_queue<pair<int, int>> pq;
		pq.push({ 0, 0 });

		while (!pq.empty()) {
			int cost = -pq.top().first;
			int here = pq.top().second;
			pq.pop();

			if (dist[here] < cost) continue;

			for (int i = 0; i < adj[here].size(); i++) {
				int there = adj[here][i].first;
				int nextDist = cost + adj[here][i].second;

				if (dist[here] == 987654321 || dist[there] > nextDist) {
					dist[there] = nextDist;
					pq.push({ -nextDist, there });
				}
			}
		}


		int ans = 0;

		for (int i = 0; i < n; i++) {
			ans += dist[fire[i]];
		}

		printf("%d\n", ans);
	}
}