#include <stdio.h>
#include <algorithm>

using namespace std;

int n, m;
int parent[1000000 + 1];

int find(int a) {
	if (a == parent[a]) {
		return a;
	}

	return parent[a] = find(parent[a]);
}


void merge(int a, int b) {
	int x = find(a);
	int y = find(b);

	if (x == y) {
		return;
	}

	//if (x > y) {
	//	swap(x, y);
	//}

	parent[x] = y;
}
int main() {
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	while (m--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);

		if (a == 0) {
			merge(b, c);
		}
		else {
			if (find(b) != find(c)) {
				printf("NO\n");
			}
			else {
				printf("YES\n");
			}
		}
	}
}