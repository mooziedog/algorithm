#include <stdio.h>
#include <vector>

using namespace std;

struct TreeNode {
	int x, y, r;
	vector<TreeNode> child;
};

vector<TreeNode> tree;
int C;
int N;

int sqr(int x) {
	return x * x;
}

bool sqrDist(TreeNode& root, TreeNode& child) {
	return sqr(root.y - child.y) + sqr(root.x - child.x);
}

bool enclose(TreeNode& root, TreeNode& child) {
	return (root.r > child.r && sqrDist(root, child) < sqr(root.r - child.r));
}

bool isEqual(TreeNode& a, TreeNode& b) {
	return (a.x == b.x && a.y == b.y && a.r == b.r);
}
 6g vf
bool isChild(TreeNode& root, TreeNode& child) {
	//printf("Root!! x=%d y=%d r=%d\n", root.x, root.y, root.r);
	//printf("Child! x=%d y=%d r=%d\n", child.x, child.y, child.r);
	if (!enclose(root, child)) return false;
	for (int i = 1; i < N; i++) {
		if (!isEqual(root, tree[i]) && !isEqual(child, tree[i]) && enclose(root, tree[i]) && enclose(tree[i], child)) {
			//printf("not child\n");
			return false;
		}
	}
	//printf("child\n");
	return true;
}

TreeNode getTree(TreeNode& root) {
	//printf("Get Tree! x=%d y=%d r=%d\n", root.x, root.y, root.r);
	TreeNode ret;
	
	for (int i = 1; i < N; i++) {
		if (isChild(root, tree[i])) {
			TreeNode temp = getTree(tree[i]);
			//printf("Get Tree! x=%d y=%d r=%d\n", root.x, root.y, root.r);
			ret.child.push_back(temp);
		}
	}

	return ret;
}

void printChild(TreeNode& root) {
	
	for (int i = 0; i < root.child.size(); i++) {
		printf("Root Node x=%d y=%d r=%d\n", root.x, root.y, root.r);
		printChild(root.child[i]);
	}
}

int main() {
	scanf("%d", &C);

	while (C--) {
		scanf("%d", &N);
		tree.clear();

		TreeNode node;
		for (int i = 0; i < N; i++) {
			scanf("%d%d%d", &node.x, &node.y, &node.r);
			tree.push_back(node);
		}

		// 입력 확인
		/*for (int i = 0; i < N; i++) {
			printf("Node #%d:x=%d y=%d r=%d\n", i+1, tree[i].x, tree[i].y, tree[i].r);
		}*/

		tree[0].child.push_back(getTree(tree[0]));

		printChild(tree[0]);
	}
}