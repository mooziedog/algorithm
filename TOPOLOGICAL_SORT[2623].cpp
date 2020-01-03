#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> v[1000 + 1];
int line[1000 + 1];
int main() {
	scanf("%d%d", &N, &M);

	for (int i = 1; i <= M; i++) {
		int num;
		scanf("%d", &num);

		int prev;
		scanf("%d", &prev);

		for (int j = 1; j < num; j++) {
			int curr;
			scanf("%d", &curr);

			line[curr]++;

			v[prev].push_back(curr);

			prev = curr;
		}
	}

	queue<int> q;
	vector<int> result;

	for (int i = 1; i <= N; i++) {
		if (line[i] == 0) {
			q.push(i);
		}
	}

	for (int i = 1; i <= N; i++) {
		if (q.empty()) {
			printf("0");
			return 0;
		}

		int curr = q.front();
		q.pop();

		result.push_back(curr);

		for (int j = 0; j < v[curr].size(); j++) {
			int next = v[curr][j];

			if (--line[next] == 0) {
				q.push(next);

			}
		}


	}

	for (int i = 0; i < result.size(); i++) {
		printf("%d\n", result[i]);
	}

}