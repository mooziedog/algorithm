#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	int a, b, val;
};

int N, M;
int parent[100000 + 1];
vector<Node> v;
bool chk;

bool cmp(Node a, Node b) {
	return a.val < b.val;
}

int find(int x) {
	if (x == parent[x]) {
		return x;
	}

	return parent[x] = find(parent[x]);
}

void merge(Node vv) {
	chk = false;

	int x = find(vv.a);
	int y = find(vv.b);

	if (x == y) {
		return;
	}

	parent[x] = y;
	chk = true;
}

int main() {
	scanf("%d%d", &N, &M);

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 1; i <= M; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		v.push_back({ a, b, c });
	}

	sort(v.begin(), v.end(), cmp);

	int sum = 0;
	int last = 0;
	for (int i = 0; i < M; i++) {
		int x = find(v[i].a);
		int y = find(v[i].b);

		if (x == y) {
			continue;
		}

		parent[x] = y;

		sum += v[i].val;
		last = v[i].val;
	}

	printf("%d\n", sum - last);
}