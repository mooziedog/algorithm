//https://www.crocus.co.kr/987?category=159837
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int query(vector<int> &tree, int node, int start, int end, int left, int right) {
	if (right < start || left > end) {
		return 0;
	}

	if (start >= left && end <= right) {
		return tree[node];
	}

	int mid = (start + end) / 2;

	return query(tree, node * 2, start, mid, left, right) + query(tree, node * 2 + 1, mid + 1, end, left, right);
}

void update(vector<int>& tree, int node, int start, int end, int idx) {
	if (!(start <= idx && idx <= end))
		return;

	tree[node] += 1;

	if (start != end)
	{
		int mid = (start + end) / 2;
		update(tree, node * 2, start, mid, idx);
		update(tree, node * 2 + 1, mid + 1, end, idx);
	}
}



int N;
int main() {
	scanf("%d", &N);

	vector<pair<int, int>> a;

	int h = (int)ceil(log2(500000));
	int tree_size = 1 << (h + 1);
	vector<int> tree(tree_size);

	for (int i = 0; i < N; i++) {
		int val;
		scanf("%d", &val);
		a.push_back({ val, i });
	}

	sort(a.begin(), a.end());

	// ÁÂÇ¥¾ÐÃà
	for (int i = 0; i < N; i++) {
		a[i].first = i;
	}

	sort(a.begin(), a.end(), cmp);

	for (int i = 0; i < N; i++) {
		//printf("%d=%d\n", a[i].first, a[i].second);
		printf("%d\n", i - query(tree, 1, 0, 500000, 0, a[i].first) + 1);

		update(tree, 1, 0, 500000, a[i].first);
	}


}