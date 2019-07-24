#include <stdio.h>
#include <queue>

using namespace std;

int N, M;
int map[1001][1001];
int dist[1001][1001][2];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

struct Map {
	int x;
	int y;
	int z;
};

int bfs() {
	queue<Map> q;
	q.push({ 1,1,0 });
	dist[1][1][0] = 1;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;

		q.pop();

		if (x == N && y == M) return dist[x][y][z];

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
		//	printf("nx:%d ny:%d z:%d\n", nx, ny, z);
			if (dist[nx][ny][z]) continue;
			if (nx > 0 && nx <= N && ny > 0 && ny <= M) {
				if (map[nx][ny] == 0) {
					q.push({ nx, ny, z });
					dist[nx][ny][z] = dist[x][y][z] + 1;
					//printf("move to x>[%d] y>[%d] dist=[%d]\n", nx, ny, dist[nx][ny][z]);
				}
				else if (map[nx][ny] == 1 && z == 0) {
					q.push({ nx, ny, 1 });
					dist[nx][ny][1] = dist[x][y][z] + 1;
					//printf("move to x>[%d] y>[%d] dist=[%d]\n", nx, ny, dist[nx][ny][z]);
				}
			}
		}
	}


}

int main() {

	scanf("%d%d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &map[i][j]);
			//printf("%d", map[i][j]);
		}
		//printf("\n");
	}

	int result = bfs();
	if (result == 0) {
		printf("-1");
	}
	else {
		printf("%d", result);
	}

}