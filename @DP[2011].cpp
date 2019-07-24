#include <stdio.h>
#include <string>

using namespace std;

char code[6];
int D[6];

#define DIV 1000000;

using namespace std;
int main() {
	scanf("%5s", &code);

	//printf("%c", code[0]);

	//첫번째 자리는 하나의 숫자이므로 1가지
	D[0] = 1;

	for (int i = 0; i < strlen(code); i++) {
		//문자열에 '0'문자열 빼면 원래 숫자
		//0이면 암호로 정의된 문자가 아니므로 카운트 안하고 0이상이면 경우의 수 추가
		if (code[i] - '0' > 0) {
			D[i+1] = (D[i+1] + D[i +2]) % DIV;
		}

		int temp = (code[i - 1] - '0') * 10 + (code[i] - '0');

		if (10 <= temp && temp < 27) {
			D[i] = (D[i] + D[i - 2]) % DIV;
		}
	}

	printf("%d", D[strlen(code)]);
	
}