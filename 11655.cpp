#include <stdio.h>

char S[101];

int main() {
	//printf("%d %d %d %d", 'a', 'A', 'z', 'Z');
	//A~Z = 65~90, a~z = 97~122
	scanf("%[^\n]", &S);

	for (int i = 0; i < 101; i++) {
		if (S[i] == '\0') {
			break;
		}
		//printf("%d\n", S[i]);
			if ((S[i] >= 65 && S[i] <= 90)) {
				if (S[i] + 13 > 90) {
					S[i] -= 26;
				}

				S[i] += 13;
			}
			else if ((S[i] >= 97 && S[i] <= 122)) {
				if (S[i] + 13 > 122) {
					S[i] -= 26;
				}

				S[i] += 13;
			}
			printf("%c", S[i]);
		//printf("%c", S[i]);
	}



}