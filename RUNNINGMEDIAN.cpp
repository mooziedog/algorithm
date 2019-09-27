#include <stdio.h>
#include <vector>

using namespace std;

//Test Case Count
int C;

vector<int> heap;

void push_heap(vector<int>& s, int newValue) {
	s.push_back(newValue);

	int index = s.size() - 1;

	while (index > 0 && s[index] > s[(index - 1) / 2]) {
		swap(s[index], s[(index - 1) / 2]);
		index = (index - 1) / 2;
	}

}

int main() {
	scanf("%d", &C);

	while (C--) {
		int N, a, b;
		int A[200001];
		A[0] = 1983;
		// 수열의 길이
		scanf("%d", &N);

		// 수열 생성 난수 a, b
		scanf("%d%d", &a, &b);

		for (int i = 1; i <= N; i++) {
			A[i] = (A[i - 1] * a + b) % 20090711;
			//printf("%d\n", A[i]);
			push_heap(heap, A[i]);
		}

		for (int i = 0; i < N; i++) {
			printf("%d\n", heap[i]);
		}

		//printf("%d", N / 2);
		//printf("%d\n", heap[N / 2] * N % 20090711);
	}
}