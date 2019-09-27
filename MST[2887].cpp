#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct Space {
	int x, y, z;
};

struct Edge {
	int v1, v2, dist;
};

Space spaces[100000];
Edge edges[100000];
int group[100001];
int N;
int cnt;

bool cmpx(Space a, Space b) {
	return a.x < b.x;
}

bool cmpy(Space a, Space b) {
	return a.y < b.y;
}

bool cmpz(Space a, Space b) {
	return a.z < b.z;
}

int find(int a) {
	if (group[a] == a)return a;
	return group[a] = find(group[a]);
}

void make_union(int a, int b) {
	int g1 = find(a);
	int g2 = find(b);

	if (g1 == g2)return;
	cnt++;
	group[g2] = g1;
}


int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		spaces[i].x = x;
		spaces[i].y = y;
		spaces[i].z = z;
	}

	sort(spaces, spaces+N-1, cmpx);

	int idx = 0;
	for (int i = 0; i < N - 1; i++) {
		edges[idx].v1 = i;
		edges[idx].v2 = i+1;
		edges[idx++].dist = abs(spaces[i].x - spaces[i + 1].x);
	}

	sort(spaces, spaces + N - 1, cmpy);

	for (int i = 0; i < N - 1; i++) {
		edges[idx].v1 = i;
		edges[idx].v2 = i + 1;
		edges[idx++].dist = abs(spaces[i].y - spaces[i + 1].y);
	}

	sort(spaces, spaces + N - 1, cmpz);

	for (int i = 0; i < N - 1; i++) {
		edges[idx].v1 = i;
		edges[idx].v2 = i + 1;
		edges[idx++].dist = abs(spaces[i].z - spaces[i + 1].z);
	}

	//ũ�罺Į
	cnt = 0;
	long long sum = 0;
	for (int i = 1; i <= N; i++)group[i] = i;
	sort(edges, edges + idx);
	for (int i = 0; i < idx; i++) {
		if (find(edges[i].v1) == find(edges[i].v2))continue;
		make_union(edges[i].v1, edges[i].v2);
		sum += edges[i].dist;
		if (cnt == N - 1)break;
	}
	printf("%lld\n", sum);

	//int idx = 0;
	//for (int i = 0; i < N - 1; i++) {
	//	edges[i].v1 = 1;
	//}
}