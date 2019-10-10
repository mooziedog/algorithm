#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>

using namespace std;

struct Circle {
	int x, y, r;
};

struct Edge {
	int u, v;
	double w;

	bool operator < (const Edge a) const {
		return w < a.w;
	}
};

double calc(Circle a, Circle b) {
	return sqrt(pow(a.x - b.x, 2.0) + pow(a.y - b.y, 2.0));
}

int find(vector<int>& r, int k) {
	if (k == r[k]) return k;
	return r[k] = find(r, r[k]);
}

bool merge(vector<int>& root, int p, int q) {
	p = find(root, p);
	q = find(root, q);
	if (p == q) return false;
	root[q] = p;
	return true;
}

int T;
int main() {
	scanf("%d", &T);

	while (T--) {
		int w, n;
		scanf("%d%d", &w, &n);

		vector<Edge> edges;
		vector<Circle> circles(n);
		vector<int> parent(n+2);
		
		int LEFT = n;
		int RIGHT = n + 1;

		for (int i = 0; i < n; i++) {
			scanf("%d%d%d", &circles[i].x, &circles[i].y, &circles[i].r);
		}

		edges.push_back({ LEFT, RIGHT, (double)w });
		parent[LEFT] = LEFT;
		parent[RIGHT] = RIGHT;

		for (int i = 0; i < n; i++) {
			parent[i] = i;
			edges.push_back({ i, LEFT, (double)max(0, circles[i].x - circles[i].r) });
			edges.push_back({ i, RIGHT, (double)max(0, w-circles[i].x - circles[i].r) });

			for (int j = i + 1; j < n; j++) {
				double dist = calc(circles[i], circles[j]) - circles[i].r - circles[j].r;
				edges.push_back({ i, j, dist });
			}
		}

		sort(edges.begin(), edges.end());

		for (int i = 0; i < edges.size(); i++) {
			if (merge(parent, edges[i].u, edges[i].v)) {
				if (find(parent, n) == find(parent, n + 1)) {
					if (!edges[i].w)puts("0");
					else printf("%.6lf\n", edges[i].w / 2);
					break;
				}
			}
		}

		edges.clear();
		circles.clear();
		parent.clear();

	}
}