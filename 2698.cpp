#include <stdio.h>

int main() {
	int T;
	int d[101][101][2] = { 0, };

	d[1][0][0] = 1;
	d[1][0][1] = 1;

	scanf("%d", &T);

	for (int i = 2; i <= 100; i++) {
		d[i][0][0] = d[i - 1][0][0] + d[i - 1][0][1];
		d[i][0][1] = d[i - 1][0][0];
		for (int j = 1; j <= i; j++) {
			d[i][j][0] += d[i - 1][j][0] + d[i - 1][j][1];
			d[i][j][1] += d[i - 1][j][0] + d[i - 1][j - 1][1];
		}
	}

	while (T--) {
		int n, k;
		scanf("%d%d", &n, &k);

		printf("%d\n", d[n][k][0] + d[n][k][1]);

	}
}