#include <stdio.h>
#include <vector>

using namespace std;

int N;
vector<pair<int, bool>> v[101];
int main() {

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int x;
			scanf("%d", &x);
			v[i].push_back(make_pair(j, x));
			//v[j].push_back(make_pair(i, x));
			//printf("%d", D[i][j]);
		}
		//printf("\n");
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			printf("%d,%d = %d\n", i, v[i].at(j).first, v[i].at(j).second);
		}
	}


}