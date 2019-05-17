// https://twpower.github.io/73-how-to-implement-dfs-and-bfs-in-cpp

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void dfs(int start, vector<int> graph[], bool check[]) {
	check[start] = true;
	printf("%d ", start);

	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];
		//방문하지 않았다면
		if (check[next] == false) {
			dfs(next, graph, check);
		}
	}
}

void bfs(int start, vector<int> graph[], bool check[]) {
	queue<int> q;

	q.push(start);
	check[start] = true;

	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		printf("%d ", tmp);

		for (int i = 0; i < graph[tmp].size(); i++) {
			if (check[graph[tmp][i]] == false) {
				q.push(graph[tmp][i]);
				check[graph[tmp][i]] = true;
			}
		}
	}
}

int main() {
	int n, m, start;
	scanf("%d%d%d", &n, &m, &start);

	vector<int> graph[10001];

	bool check[10001];

	fill(check, check+10001, false);

	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);

		graph[u].push_back(v);
		graph[v].push_back(u);
		
	}

	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}


	//dfs
	dfs(start, graph, check);
	printf("\n");

	fill(check, check + 10001, false);
	//bfs
	bfs(start, graph, check);


}