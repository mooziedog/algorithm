#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int V, E;
int delay[500 + 1];
int adj[500 + 1][500 + 1];
int W[500 + 1][500 + 1];

int T;

void solve() {
	vector<pair<int, int>> order;
	for (int i = 1; i <= V; i++) {
		order.push_back({ delay[i], i });
	}

	sort(order.begin(), order.end());

	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if (i == j) {
				W[i][j] = 0;
			}
			else {
				W[i][j] = adj[i][j];
			}
		}
	}

	int ret = 98765321;

	for (int k = 1; k <= V; k++) {
		int w = order[k-1].second;
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				adj[i][j] = min(adj[i][j], adj[i][w] + adj[w][j]);
				W[i][j] = min(adj[i][w] + delay[w] + adj[w][j], W[i][j]);
			}
		}
	}

}

int main() {
	scanf("%d%d", &V, &E);

	for(int i = 1; i <= V; i++) {
		scanf("%d", &delay[i]);
	}

	for (int i = 1; i <= V; ++i)
		for (int j = 1; j <= V; ++j)
			adj[i][j] = 987654321;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		adj[a][b] = c;
		adj[b][a] = c;
	}

	solve();

	scanf("%d", &T);

	while (T--) {
		int s, t;
		scanf("%d%d", &s, &t);
		printf("%d\n", W[s][t]);
	}


}