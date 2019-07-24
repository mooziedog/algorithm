#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int C;

//���ĺ��� �� ���ڿ� ���� ������� ǥ��
//���� (i,j)�� ���ĺ� i�� j���� �տ� �;� ���� ��Ÿ����.
vector<vector<int>> adj;
//�־��� �ܾ��κ��� ���ĺ� ���� ���İ��� �׷����� �����Ѵ�.
void makeGraph(const vector <string>& words) {
	adj = vector<vector<int>>(26, vector<int>(26, 0));
	for (int j = 1; j < words.size(); ++j) {
		int i = j - 1, len = min(words[i].size(), words[j].size());
		//word[i]�� word[j] �տ� ���� ������ ã�´�.
		for (int k = 0; k < len; ++k) {
			if (words[i][k] != words[j][k]) {
				int a = words[i][k] - 'a';
				int b = words[j][k] - 'a';
				adj[a][b] = 1;
				break;
			}
		}
	}
}

vector<int> seen, order;
void dfs(int here) {
	seen[here] = 1;
	for (int there = 0; there < adj.size(); ++there) {
		if (adj[here][there] && !seen[there]) {
			dfs(there);
		}
	}
	order.push_back(here);
}

//adj�� �־��� �׷����� ���������� ����� ��ȯ�Ѵ�.
// �׷����� DAG�� �ƴ϶�� �� ���͸� ��ȯ�Ѵ�.
vector<int> topologicalSort() {
	int n = adj.size();
	seen = vector<int>(n, 0);
	order.clear();

	for (int i = 0; i < n; ++i) {
		if (!seen[i]) {
			dfs(i);
		}
	}
	reverse(order.begin(), order.end());

	//���� �׷����� DAG�� �ƴ϶�� ���İ���� ������ ������ �ִ�.
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (adj[order[j]][order[i]]) {
				return vector<int>();
			}
		}
	}
	//���� ����� ���� �켱 Ž������ ���� ������ ��ȯ�Ѵ�.
	return order;
}

int main() {
	scanf("%d", &C);

	while (C--) {
		int n;
		scanf("%d", &n);

		vector<string> words(n);

		for (int i = 0; i < n; i++) {
			cin >> words[i];
		}

		makeGraph(words);

		vector<int> result = topologicalSort();
		if (result.empty()) {
			printf("INVALID HYPOTHESIS\n");
		}
		else {
			for (int i = 0; i < result.size(); i++) {
				printf("%c", result[i] + 'a');
			}
			printf("\n");
		}
	}
}