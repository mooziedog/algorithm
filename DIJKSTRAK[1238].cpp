#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	int N, M, X;
	scanf("%d%d%d", &N, &M, &X);

	vector<int> go_dist(1001, 987654321);
	vector<int> return_dist(1001, 987654321);
	vector<pair<int, int>> go_edge[1001];
	vector<pair<int, int>> return_edge[1001];

	for (int i = 0; i < M; i++) {
		int x, y, t;
		scanf("%d%d%d", &x, &y, &t);

		go_edge[x].push_back({ y, t });
		return_edge[y].push_back({ x, t });
	}

	priority_queue<pair<int, int>> pq;
	go_dist[X] = 0;
	pq.push({ 0, X });

	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = -pq.top().first;

		pq.pop();

		if (go_dist[here] > cost) continue;

		for (int i = 0; i < go_edge[here].size(); i++) {
			int next = go_edge[here][i].first;
			int nextDist = go_edge[here][i].second + cost;

			if (go_dist[next] > nextDist) {
				go_dist[next] = nextDist;
				pq.push({ -nextDist, next });
			}
		}
	}

	return_dist[X] = 0;
	pq.push({ 0, X });

	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = -pq.top().first;

		pq.pop();

		if (return_dist[here] > cost) continue;

		for (int i = 0; i < return_edge[here].size(); i++) {
			int next = return_edge[here][i].first;
			int nextDist = return_edge[here][i].second + cost;

			if (return_dist[next] > nextDist) {
				return_dist[next] = nextDist;
				pq.push({ -nextDist, next });
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) ans = max(ans, go_dist[i] + return_dist[i]);
	printf("%d\n", ans);

}