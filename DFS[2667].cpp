//https://blockdmask.tistory.com/175

#include <stdio.h>
#include <algorithm>

using namespace std;

//지도의 크기
int N;
// 단지 정보
int map[26][26] = { 0, };
// 각 단지의 크기
int areaSize[350];
// 총 단지의 수
int totalAreaCount;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

void dfs(int x, int y) {
	map[x][y] = 0;
	areaSize[totalAreaCount]++;
	for (int i = 0; i < 4; i++) {
		if (x + dx[i] > 0 && y + dy[i] > 0 && map[x + dx[i]][y + dy[i]] == 1 && x + dx[i] <= N && y + dy[i] <= N) {
//			printf("move to >>>> x:%d y:%d visited:%d\n", x + dx[i], y + dy[i], map[x + dx[i]][y + dy[i]]);
			dfs(x + dx[i], y + dy[i]);
		}
	}
}

int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 1) {
//				printf("start ===> %d%d\n", i, j);
				dfs(i, j);
				totalAreaCount++;
			}
		}
	}

	printf("%d\n", totalAreaCount);

	sort(areaSize, areaSize + totalAreaCount);

	for (int i = 0; i < totalAreaCount; i++) {
		printf("%d\n", areaSize[i]);
	}
	
}