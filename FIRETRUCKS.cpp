#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int C;
int main() {
	scanf("%d", &C);

	while (C--) {
		int V, E, n, m;

		scanf("%d%d%d%d", &V, &E, &n, &m);

		vector<int> dist(V + 1, 987654321);
		vector<vector<pair<int, int>>> edge(V + 1);

		for (int i = 0; i < E; i++) {
			int a, b, t;
			scanf("%d%d%d", &a, &b, &t);

			edge[a].push_back({ b, t });
			edge[b].push_back({ a, t });
		}

		vector<int> fire;
		for (int i = 0; i < n; i++) {
			int temp;
			scanf("%d", &temp);
			fire.push_back(temp);
		}

		vector<int> fireStation;
		for (int i = 0; i < m; i++) {
			int temp;
			scanf("%d", &temp);
			fireStation.push_back(temp);
			edge[0].push_back({ temp, 0 });
			edge[temp].push_back({ 0, 0 });
		}

		priority_queue<pair<int, int>> pq;

		pq.push({ 0, 0 });

		while (!pq.empty()) {
			int here = pq.top().second;
			int cost = -pq.top().first;

			pq.pop();

			if (cost > dist[here]) continue;

			for (int i = 0; i < edge[here].size(); i++) {
				int there = edge[here][i].first;
				int nextDist = edge[here][i].second + cost;

				if (dist[there] > nextDist) {
					dist[there] = nextDist;
					pq.push({ -nextDist, there });
				}
			}
		}

		int result = 0;
		for (int i = 0; i < n; i++) {
			result += dist[fire[i]];
		}

		printf("%d\n", result);
	}
}