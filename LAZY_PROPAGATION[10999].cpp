#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

long long init(vector<long long> &s, vector<long long> &tree, int node, int start, int end) {
	if (start == end) {
		return tree[node] = s[start];
	}

	int mid = (start + end) / 2;

	return tree[node] = init(s, tree, node * 2, start, mid) + init(s, tree, node * 2 + 1, mid + 1, end);
}

//Segment tree
void update(vector<long long>& tree, int node, int start, int end, int index, long long diff) {
	if (index < start || index > end) {
		return;
	}
	tree[node] = tree[node] + diff;

	int mid = (start + end) / 2;
	if (start != end) {
		update(tree, node * 2, start, mid, index, diff);
		update(tree, node * 2 + 1, mid + 1, end, index, diff);
	}
}

void update_range(vector<long long>& tree, int node, int start, int end, int index, long long diff) {
	if (index < start || index > end) {
		return;
	}

	if (start == end) {
		tree[node] = tree[node] + diff;
	}

	int mid = (start + end) / 2;
	
	update(tree, node * 2, start, mid, index, diff);
	update(tree, node * 2 + 1, mid + 1, end, index, diff);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long sum(vector<long long>& tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return 0;
	}

	if (left <= start && right >= end) {
		return tree[node];
	}

	int mid = (start + end) / 2;

	return sum(tree, node * 2, start, mid, left, right) + sum(tree, node * 2 + 1, mid + 1, end, left, right);
}

int N, M, K;
int main() {
	//수의 개수
	scanf("%d%d%d", &N, &M, &K);

	vector<long long> s(N);

	for (int i = 0; i < N; i++) {
		scanf("%lld", &s[i]);
	}
	
	int h = (int)ceil(log2(N));
	int tree_size = 1 << (h + 1);

	vector<long long> tree(tree_size);

	init(s, tree, 1, 0, N - 1);

	for (int i = 0; i < M + K; i++) {
		int a;
		scanf("%d", &a);
		if (a == 1) {
			int b, c;
			long long d;
			scanf("%d%d%lld", &b, &c, &d);

			for (int j = b; j <= c; j++) {
				s[j - 1] = s[j-1] + d;
				update_range(tree, 1, 0, N - 1, j-1, d);
			}
		}
		else {
			int b, c;
			scanf("%d%d", &b, &c);
			printf("%lld\n", sum(tree, 1, 0, N-1, b-1, c-1));
		}
	}

}