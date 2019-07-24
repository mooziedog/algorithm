#include <stdio.h>
#include <vector>

using namespace std;

vector<pair<int, int>> tree[27];

int N;

//preOrder ������ȸ
void preorder(int root) {
	printf("%c", root);
	if (tree[root - 'A'].front().first != '.') {
		preorder(tree[root - 'A'].front().first);
	}

	if (tree[root - 'A'].front().second != '.') {
		preorder(tree[root - 'A'].front().second);
	}
	
}


//inOrder ������ȸ
void inorder(int root) {

	if (tree[root - 'A'].front().first != '.') {
		inorder(tree[root - 'A'].front().first);
	}

	printf("%c", root);
	if (tree[root - 'A'].front().second != '.') {
		
		inorder(tree[root - 'A'].front().second);
	}

	
}

//PostOrder ������ȸ
void postorder(int root) {

	if (tree[root - 'A'].front().first != '.') {
		postorder(tree[root - 'A'].front().first);
	}

	if (tree[root - 'A'].front().second != '.') {
		postorder(tree[root - 'A'].front().second);
	}

	printf("%c", root);
}


int main() {
	scanf("%d", &N);

	for (int n = 1; n <= N; n++) {
		char root;
		char left;
		char right;

		scanf(" %c %c %c", &root, &left, &right);

		tree[root - 'A'].push_back(make_pair(left, right));
	}

	preorder('A');
	printf("\n");
	inorder('A');
	printf("\n");
	postorder('A');
}
