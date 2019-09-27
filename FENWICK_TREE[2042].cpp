#include <stdio.h>
#include <vector>

using namespace std;

void update(vector<long long>& tree, int i, long long diff) {
	while (i < tree.size()) {
		tree[i] += diff;
		i += (i & -i);
	}
}

long long sum(vector<long long>& tree, int i) {
	long long sum = 0;
	while (i > 0) {
		sum += tree[i];
		i -= (i & -i);
	}
	return sum;
}

int N, M, K;
int main() {
	scanf("%d%d%d", &N, &M, &K);

	vector<long long> tree(N+1);
	vector<long long> S(N+1);

	for (int i = 1; i <= N; i++) {
		scanf("%lld", &S[i]);
		update(tree, i, S[i]);
	}

	for (int i = 1; i <= M + K; i++) {
		int a;
		scanf("%d", &a);

		if (a == 1) {
			int b;
			long long c;
			scanf("%d%lld", &b, &c);

			long long diff = c - S[b];
			S[b] = c;
			update(tree, b, diff);

		}
		else {
			int b, c;
			scanf("%d%d", &b, &c);
			printf("%lld\n", sum(tree, c) - sum(tree, b-1));
		}
	}


}