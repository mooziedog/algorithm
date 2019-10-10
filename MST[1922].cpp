#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
	int a, b, c;

	bool operator < (const edge a) const {
		return c < a.c;
	}
};



int N, M;
vector<edge> v;
vector<int> parent(1001);

int find(int x) {
	if (x == parent[x]) {
		return x;
	}

	return parent[x] = find(parent[x]);
}

int main() {
	scanf("%d%d", &N, &M);

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int a, b, c;

		scanf("%d%d%d", &a, &b, &c);

		v.push_back({ a, b, c });
	}

	sort(v.begin(), v.end());

	int result = 0;

	for (int i = 0; i < v.size(); i++) {
		int x = find(v[i].a);
		int y = find(v[i].b);

		if (x == y) continue;

		parent[x] = y;

		result += v[i].c;

	}

	printf("%d\n", result);


}