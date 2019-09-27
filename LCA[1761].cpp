//https://www.crocus.co.kr/663
//https://jason9319.tistory.com/110

#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

int N, M, h;
vector<vector<pair<int, int>>> vt;
bool visited[40000 + 1];
int depth[40000 + 1];
int par[40000 + 1][21];
int dist[40000 + 1];

void dfs(int here, int dph, int dst) {
	visited[here] = true;
	depth[here] = dph;
	dist[here] = dst;

	for (pair<int, int> there : vt[here]) {
		if (visited[there.first]) continue;

		par[there.first][0] = here;

		dfs(there.first, dph + 1, there.second + dst);
	}
}

void f() {
	for (int j = 1; j < h; j++) {
		for (int i = 1; i <= N; i++) {
			par[i][j] = par[par[i][j - 1]][j - 1];
		}
	}
}

int lca(int a, int b) {
	if (depth[a] > depth[b]) {
		swap(a, b);
	}

	for (int i = h; i >= 0; i--) {
		if (depth[b] - depth[a] >= (1 << i)) {
			b = par[b][i];
		}
	}

	if (a == b) return  a;

	for (int i = h; i >= 0; i--) {
		if (par[a][i] != par[b][i]) {
			a = par[a][i];
			b = par[b][i];
		}
	}

	return par[a][0];
}

int main() {
	scanf("%d", &N);

	vt.resize(N + 1);

	h = (int)ceil(log2(N));

	for (int i = 1; i < N; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		vt[a].push_back({ b, c });
		vt[b].push_back({ a, c });
	}

	dfs(1, 0, 0);
	f();

	scanf("%d", &M);

	while (M--) {
		int a, b;
		scanf("%d%d", &a, &b);
		int qlca = lca(a, b);

		int result = dist[a] + dist[b] - 2 * dist[qlca];
		printf("%d\n", result);
	}

}