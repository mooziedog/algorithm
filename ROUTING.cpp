#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int C;
vector<vector<pair<int, double>>> v;
int main() {
	scanf("%d", &C);

	for (int c = 1; c <= C; c++) {
		int N, M;
		scanf("%d%d", &N, &M);
		
		v.clear();
		v.resize(N);
		vector<double> dist(N, 0.0);

		while (M--) {
			int a, b;
			double c;
			scanf("%d%d%lf", &a, &b, &c);
			v[a].push_back(make_pair(b, c));
			v[b].push_back(make_pair(a, c));
		}

		dist[0] = 1.0;
		priority_queue<pair<double, int>> pq;
		pq.push({ -dist[0], 0 });

		while (!pq.empty()) {
			double cost = -pq.top().first;
			int here = pq.top().second;
			pq.pop();

			if (dist[here] < cost) continue;

			for (int i = 0; i < v[here].size(); i++) {
				int there = v[here][i].first;
				double ccost = cost * v[here][i].second;

				if (dist[there] == 0.0 || dist[there] > ccost) {
					dist[there] = ccost;
					pq.push({ -ccost, there });
				}
			}
		}



		printf("%.10lf\n", dist[N-1]);

	}
}