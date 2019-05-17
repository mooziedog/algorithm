#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int N, M;
char map[102][102];
int visited[101][101] = { 0, };
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	
	while (!q.empty()) {
		int xx = q.front().first;
		int	yy = q.front().second;

		q.pop();

		if (xx == N && yy == M) {
			break;
		}
		
		for (int i = 0; i < 4; i++) {
			if (xx + dx[i] > 0 && xx + dx[i] <= N && yy + dy[i] > 0 && yy + dy[i] <= M && map[xx + dx[i]][yy + dy[i]-1] == '1'&& !visited[xx + dx[i]][yy + dy[i]]) {
				visited[xx + dx[i]][yy + dy[i]] = visited[xx][yy] + 1;
				q.push(make_pair(xx + dx[i], yy + dy[i]));

//				printf("position : %c\n", map[xx + dx[i]][yy + dy[i] - 1]);
//				printf("x:%d y:%d count=%d\n", xx, yy, visited[xx][yy]);
			}
		}
	}

	return visited[N][M];
}



int main() {
	scanf("%d%d", &N, &M);

	for (int i = 1; i <= N; i++) {
			scanf("%s", map[i]);
	}

	visited[1][1] = 1;

	printf("%d\n", bfs(1, 1));

}