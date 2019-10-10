#include <stdio.h>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int n;
vector<int> parent(101);
vector<pair<double, double>> edge;
double result;

double calc(pair<double, double>& a, pair<double, double>& b) {
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int find(int x) {
	if (x == parent[x]) return x;

	return parent[x] = find(parent[x]);
}

void merge(int x, int y, double z) {
	int xx = find(x);
	int yy = find(y);

	if (xx == yy) return;

	result += z;

	parent[xx] = yy;
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n;i++) {
		double x, y;
		scanf("%lf%lf", &x, &y);
		edge.push_back({ x, y });
		parent[i] = i;
	}

	priority_queue<pair<double, pair<int, int>>> pq;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			double dist = calc(edge[i], edge[j]);
			//printf("%.2f\n", dist);
			pq.push({ -dist, { i, j } });
		}
	}

	while (!pq.empty()) {
		merge(pq.top().second.first, pq.top().second.second, -pq.top().first);
		pq.pop();
	}

	printf("%.2f\n", result);
}
