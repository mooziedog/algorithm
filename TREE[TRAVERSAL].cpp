#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
//Test Case
int C;

vector<int> preOrder;
vector<int> inOrder;

vector<int> slice(vector<int> v, int begin, int end) {
	vector<int> temp = vector<int>(v.begin() + begin, v.begin() + end);
	//for (int i = 0; i < temp.size(); i++) {
	//	printf("%d ", temp[i]);
	//	
	//}
	//printf("\n");
	return temp;
}


void printPostOrder(vector<int> preOrder, vector<int> inOrder) {
	if (preOrder.empty()) {
		return;
	}

	int size = preOrder.size();

	int root = preOrder[0];

	int L = find(inOrder.begin(), inOrder.end(), root) - inOrder.begin();

	//printf("Root:%d L:%d\n", root, L);

	printPostOrder(slice(preOrder, 1, L+1), slice(inOrder, 0, L));
	printPostOrder(slice(preOrder, L+1, size), slice(inOrder, L + 1, size));

	printf("%d ", root);
}

int main() {
	scanf("%d", &C);

	while (C--) {
		int N;
		scanf("%d", &N);

		preOrder.clear();
		inOrder.clear();

		for (int i = 0; i < N; i++) {
			int node;
			scanf("%d", &node);
			preOrder.push_back(node);
		}

		for (int i = 0; i < N; i++) {
			int node;
			scanf("%d", &node);
			inOrder.push_back(node);
		}

		printPostOrder(preOrder, inOrder);
		printf("\n");
	}
}