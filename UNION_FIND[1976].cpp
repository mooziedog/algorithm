#include <stdio.h>
#include <algorithm>

using namespace std;

int N, M;
int parent[200 + 1];


int find(int x) {
	if (x == parent[x]) {
		return x;
	}

	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	int a = find(x);
	int b = find(y);

	if (a == b) {
		return;
	}

	parent[a] = b;
}


int main() {
	scanf("%d%d", &N, &M);

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= N; m++) {
			int c;
			scanf("%d", &c);
			if (c == 1) {
				merge(n, m);
			}
		}
	}

	int res = 0;
	bool ans = true;;
	for (int i = 0; i < M; i++) {
		int temp;
		scanf("%d", &temp);
		if (i == 0) {
			res = find(temp);
		}
		else {
			if (res != find(temp)) {
				ans = false;
			}
		}
	}

	if (ans) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
}