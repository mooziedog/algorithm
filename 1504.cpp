#include <stdio.h>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int N, E;
vector<pair<int, long long>> v[800 + 1];

long long solution(int start, int end) {
	vector<long long> dist(N + 1, 987654321);

	dist[start] = 0;
	priority_queue<pair<long long, int>> pq;

	pq.push({ 0, start });

	while (!pq.empty()) {
		int here = pq.top().second;
		long long cost = -pq.top().first;

		pq.pop();

		if (dist[here] < cost) continue;

		for (int i = 0; i < v[here].size(); i++) {
			int there = v[here][i].first;
			long long nextDist = cost + v[here][i].second;

			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push({ -nextDist, there });
			}
		}

	}

	return dist[end];
}

int main() {
	scanf("%d%d", &N, &E);

	for (int i = 0; i < E; i++) {
		int a, b;
		long long c;

		scanf("%d%d%lld", &a, &b, &c);

		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}

	int start, end;

	scanf("%d%d", &start, &end);

	
	long long a1 = solution(1, start);
	long long a2 = solution(start, end);
	long long a3 = solution(end, N);

	long long solve1 = a1 + a2 + a3;

	a1 = solution(1, end);
	a2 = solution(end, start);
	a3 = solution(start, N);

	long long solve2 = a1 + a2 + a3;

	long long solve = min(solve1, solve2);

	if (solve >= 987654321) {
		printf("-1");
	}
	else {
		printf("%lld\n", solve);
	}
}