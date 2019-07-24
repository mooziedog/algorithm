#include <stdio.h>
#include <queue>

using namespace std;

const int RIPE_TOMATO = 1;
const int LESS_RIPE_TOMATO = 0;
const int EMPTY = -1;

//NÀÌ »õ·ÎÄ­!!
int M, N;
int box[1001][1001] = { 0, };

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

queue<pair<int, int>> q;

int occupiedSize = 0;
int maxDay = 0;

void bfs() {
	while (!q.empty()) {
		
		int x = q.front().first;
		int y = q.front().second;		
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx > 0 && nx <= M && ny > 0 && ny <= N && box[nx][ny] == LESS_RIPE_TOMATO) {
				//printf("x[%d]y[%d] = %d\n", nx, ny, box[nx][ny]);
				box[nx][ny] = box[x][y] + 1;
				maxDay = box[nx][ny];
				q.push(make_pair(nx, ny));
				occupiedSize += 1;
				//printf("x[%d]y[%d] = %d\n", nx, ny, box[nx][ny] - 1);
			}
		}
	}
}

int main() {
	scanf("%d%d", &M, &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &box[j][i]);
			if (box[j][i] == RIPE_TOMATO) {
				q.push(make_pair(j, i));
				occupiedSize += 1;
			}
			else if (box[j][i] == EMPTY) {
				occupiedSize += 1;
			}
		}
	}

	if (occupiedSize == (M * N)) {
		printf("0");
		return 0;
	}

	bfs();
	if (occupiedSize != (M * N)) {
		printf("-1");
	}
	else {
		printf("%d", maxDay - 1);
	}


}