#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

struct Net {
	int B, C;

	bool operator < (const Net a) const {
		return a.C > C;
	}
};

int N, M;
vector<vector<Net>> v;

int main() {
	scanf("%d%d", &N, &M);

	v.resize(N+1);

	for (int i = 0; i < M; i++) {
		int A, B, C;
		scanf("%d%d%d", &A, &B, &C);

		v[A].push_back({ B, C });
		v[B].push_back({ A, C });
	}

	vector<int> dist(N + 1, 9887654321);
	vector<int> parent(N + 1, -1);
	vector<pair<int, int>> result(N+1);

	priority_queue<pair<int, int>> pq;

	dist[1] = 0;

	pq.push({ 0, 1 });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (dist[here] < cost) continue;

		for (int i = 0; i < v[here].size(); i++) {
			int next = v[here][i].B;
			
			if (dist[next] > cost + v[here][i].C) {
				dist[next] = cost + v[here][i].C;
				parent[next] = here;
				pq.push({ -(cost + v[here][i].C), next });
				result.push_back({ here, next });
			}

		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (dist[i] < 987654321 && parent[i] != -1) {
			ans++;
		}
	}

		printf("%d\n", ans);
	for (int i = 1; i <= N; i++)
	{
		if (dist[i] < 987654321 && parent[i] != -1)
		{
			printf("%d %d\n", i, parent[i]);
		}
	}

}


//#include <stdio.h>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//struct Net {
//	int y, cost;
//
//	bool operator < (Net a) const {
//		return cost > a.cost;
//	}
//};
//
//int N, M;
//
//vector<vector<Net>> p;
//int main() {
//	scanf("%d%d", &N, &M);
//
//	p.resize(N + 1);
//
//	for (int i = 0; i < M; i++) {
//		int A, B, C;
//		scanf("%d%d%d", &A, &B, &C);
//
//		p[A].push_back({ B, C });
//		p[B].push_back({ A, C });
//	}
//
//	vector<int> dist(N + 1, 987654321);
//	vector<int> parent(N + 1, -1);
//
//	priority_queue<pair<int, int>> pq;
//	dist[1] = 0;
//	pq.push({ 1, dist[1] });
//
//	vector<pair<int, int>> result;
//
//	while (!pq.empty()) {
//		int curr = pq.top().first;
//		int cost = -pq.top().second;
//
//		pq.pop();
//
//		if (dist[curr] < cost) continue;
//
//		for (int i = 0; i < p[curr].size(); i++) {
//			int next = p[curr][i].y;
//			int ccost = p[curr][i].cost + cost;
//
//			if (dist[next] > ccost) {
//				dist[next] = ccost;
//				pq.push({ next, -ccost });
//				parent[next] = curr;
//				result.push_back({ curr, next });
//			}
//		}
//	}
//
//	int ans = 0;
//
//	for (int i = 1; i <= N; i++)
//	{
//		if (dist[i] < 987654321 && parent[i] != -1)
//		{
//			ans++;
//		}
//	}
//	printf("%d\n", ans);
//	for (int i = 1; i <= N; i++)
//	{
//		if (dist[i] < 987654321 && parent[i] != -1)
//		{
//			printf("%d %d\n", i, parent[i]);
//		}
//	}
//
//}