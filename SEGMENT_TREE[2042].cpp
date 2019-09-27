#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

int N, M, K;


long long init(vector<long long>& a, vector<long long>& tree, int node, int start, int end) {
	if (start == end) {
		return tree[node] = a[start];
	}

	return tree[node] = init(a, tree, node * 2, start, (start + end) / 2) + init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);

}

void update(vector<long long>& tree, int node, int start, int end, int index, long long diff) {
	if (index < start || index > end) {
		return;
	}
	tree[node] = tree[node] + diff;

	if (start != end) {
		update(tree, node * 2, start, (start + end) / 2, index, diff);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}

}

long long sum(vector<long long>& tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return  0;
	}

	if (start >= left && end <= right) {
		return tree[node];
	}

	return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2+1, (start + end) / 2 + 1, end, left, right);
}

int main() {
	scanf("%d%d%d", &N, &M, &K);
	vector<long long> S(N);

	for (int i = 0; i < N; i++) {
		scanf("%lld", &S[i]);
	}

	int h = (int)ceil(log2(N));
	int tree_size = 1 << (h + 1);

	vector<long long> tree(tree_size);

	init(S, tree, 1, 0, N - 1);

	for (int i = 0; i < M + K; i++) {
		int condition;
		scanf("%d", &condition);

		//b번째 수를 c로 변경
		if (condition == 1) {
			int b;
			long long c;
			scanf("%d%lld", &b, &c);
			b -= 1;
			long long diff = c - S[b];
			//if (diff == 0) continue;
			S[b] = c;

			update(tree, 1, 0, N - 1, b, diff);

		}
		//b부터 c까지의 합
		else {
			int b, c;

			scanf("%d%d", &b, &c);
			printf("%lld\n", sum(tree, 1, 0, N-1, b-1, c-1));
		}

	}

}