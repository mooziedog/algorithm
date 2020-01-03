#include <stdio.h>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int n;
double result;
vector<pair<double, double>> edge;
vector<int> parent;

double calc(pair<double, double> a, pair<double, double> b) {
	return sqrt(pow(b.second - a.second, 2.0) + pow(b.first - a.first, 2.0));
}

int find(int x) {
	if (x == parent[x]) return x;

	return parent[x] = find(parent[x]);
}

void merge(int x, int y, double c) {
	x = find(x);
	y = find(y);

	if (x == y) return;

	result += -c;

	parent[x] = y;
}

int main() {
	scanf("%d", &n);


	vector<double> dist(n + 1);
	parent.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		double x, y;

		scanf("%lf%lf", &x, &y);
		edge.push_back({ x, y });
		
		parent[i] = i;
	}

	priority_queue<pair<double, pair<int, int>>> pq;

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			double dist = calc(edge[i - 1], edge[j - 1]);

			pq.push({ -dist, {i, j} });
		}
	}

	while (!pq.empty()) {
		merge(pq.top().second.first, pq.top().second.second, pq.top().first);
		pq.pop();
	}

	printf("%.2lf\n", result);
}

//#include <stdio.h>
//#include <vector>
//#include <queue>
//#include <math.h>
//
//using namespace std;
//
//int n;
//int parent[100 + 1];
//double result;
//
//double calc(pair<double, double> a, pair<double, double> b) {
//	return sqrt(pow(a.first - b.first, 2.0) + pow(a.second - b.second, 2.0));
//}
//
//int find(int x) {
//	if (x == parent[x]) return x;
//
//	return parent[x] = find(parent[x]);
//}
//
//void merge(int x, int y, double c) {
//	x = find(x);
//	y = find(y);
//
//	if (x == y) return;
//
//	result += c;
//
//	parent[x] = y;
//}
//
//int main() {
//	scanf("%d", &n);
//	vector<pair<double, double>> edge;
//
//
//	for (int i = 0; i < n; i++) {
//		double x, y;
//		scanf("%lf%lf", &x, &y);
//		edge.push_back({ x, y });
//		parent[i + 1] = i + 1;
//	}
//
//	priority_queue<pair<double, pair<int, int>>> pq;
//
//	for (int i = 1; i <= n; i++) {
//		for (int j = i + 1; j <= n; j++) {
//			double dist = calc(edge[i - 1], edge[j - 1]);
//			pq.push({ -dist, {i, j} });
//		}
//	}
//
//	while (!pq.empty()) {
//		merge(pq.top().second.first, pq.top().second.second, -pq.top().first);
//		pq.pop();
//	}
//
//
//
//	printf("%.2f\n", result);
//}