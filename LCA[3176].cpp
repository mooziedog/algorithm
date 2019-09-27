#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>


using namespace std;

int N, h, K;
vector<vector<pair<int, int>>> v;
bool visited[100000 + 1];
int depth[100000 + 1];
int sdist[100000 + 1][21];
int ldist[100000 + 1][21];
int par[100000 + 1][21];

struct Result {
	int min, max, qlca;
};

void dfs(int here, int d) {
	visited[here] = true;
	depth[here] = d;
	for (pair<int, int> there : v[here]) {
		if (visited[there.first]) {
			continue;
		}

		par[there.first][0] = here;
		sdist[there.first][0] = there.second;
		ldist[there.first][0] = there.second;
		dfs(there.first, d + 1);
	}
}

void f() {
	for (int j = 1; j < h; j++) {
		for (int i = 1; i <= N; i++) {
			par[i][j] = par[par[i][j - 1]][j - 1];
			sdist[i][j] = min(sdist[i][j - 1], sdist[par[i][j - 1]][j - 1]);
			ldist[i][j] = max(ldist[i][j - 1], ldist[par[i][j - 1]][j - 1]);
		}
	}
}

Result lca(int d, int e) {
	int ansMin = 987654321;
	int ansMax = -1;
	Result result;
	if (depth[d] > depth[e]) {
		swap(d, e);
	}


	for (int i = h; i >= 0; i--) {
		if (depth[e] - depth[d] >= (1 << i)) {
			ansMin = min(ansMin, sdist[e][i]);
			ansMax = max(ansMax, ldist[e][i]);
			e = par[e][i];
		}
	}

	if (d == e) {
		result.qlca = e;
		result.min = ansMin;
		result.max = ansMax;
		return result;
	}

	for (int i = h; i >= 0; i--) {
		if (par[d][i] != par[e][i]) {
			ansMin = min(ansMin, min(sdist[d][i], sdist[e][i]));
			ansMax = max(ansMax, max(ldist[d][i], ldist[e][i]));
			d = par[d][i];
			e = par[e][i];
		}
	}

	result.qlca = par[d][0];
	result.min = min(ansMin, min(sdist[d][0], sdist[e][0]));
	result.max = max(ansMax, max(ldist[d][0], ldist[e][0]));
	return result;
}


int main() {
	scanf("%d", &N);

	h = (int)ceil(log2(N));
	v.resize(N+1);

	for (int i = 1; i < N; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);

		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}

	dfs(1, 0);
	f();

	scanf("%d", &K);

	while (K--) {
		int d, e;
		scanf("%d%d", &d, &e);

		Result result = lca(d, e);

		printf("%d %d\n", result.min, result.max);
	}
}