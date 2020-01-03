#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int line[32000 + 1];
vector<int> v[32000 + 1];
vector<int> result;
int main() {
	scanf("%d%d", &N, &M);

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d%d", &a, &b);

		line[b]++;

		v[a].push_back(b);
	}

	priority_queue<int> pq;

	for (int i = 1; i <= N; i++) {
		if (line[i] == 0) {
			pq.push(-i);
		}
	}

	for (int i = 1; i <= N; i++) {
		if (pq.empty()) {
			return 0;
		}

		int curr = -pq.top();
		pq.pop();
		result.push_back(curr);

		for (int j = 0; j < v[curr].size(); j++) {
			int next = v[curr][j];

			if (--line[next] == 0) {
				pq.push(-next);
			}
		}
	}

	for (int i = 0; i < result.size(); i++) {
		printf("%d ", result[i]);
	}
}