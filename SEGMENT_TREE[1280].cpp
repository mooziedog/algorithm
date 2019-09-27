#include <stdio.h>
#include <vector>

using namespace std;

long long init(vector<long long>& X, vector<long long>& tree, int node, int start, int end) {
	if (start == end) return;
	
}

int N;
int main() {
	/*5
		3
		4
		5
		6
		7*/

	scanf("%d", &N);

	vector<long long> X(N);

	for (int i = 0; i < N; i++) {
		scanf("%lld", &X[i]);
	}

	int h = (int)ceil(log2(N));
	int tree_size = 1 << (h + 1);

	vector<long long> tree(tree_size);
	


}