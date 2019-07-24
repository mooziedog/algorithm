#include <stdio.h>
#include <algorithm>

using namespace std;
 
int N;
long long C[1000001] = { 0, };
long long maxCardNumber;
int maxCount;

bool desc(long long x, long long y) {
	return x > y;
}

int main() {

	scanf("%d", &N);

	for(int i=1;i<=N;i++){
		scanf("%lld", &C[i]);
	}

	if (N == 1) {
		printf("%lld", C[1]);
		return 0;
	}

	sort(C+1, C + N +1, desc);

	maxCardNumber = C[1];
	maxCount++;
	int currMaxCount = 1;


	for (int i = 2; i <= N; i++) {
		//printf("%lld", C[i]);
		if (C[i] == C[i - 1]) {
			currMaxCount++;
		}
		else {
			currMaxCount = 1;
		}

		if (currMaxCount >= maxCount) {
			maxCount = currMaxCount;
			maxCardNumber = C[i];
		}

	}

	printf("%lld", maxCardNumber);


}  