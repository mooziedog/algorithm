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

	//ù��° �ڸ��� �ϳ��� �����̹Ƿ� 1����
	D[0] = 1;

	for (int i = 0; i < strlen(code); i++) {
		//���ڿ��� '0'���ڿ� ���� ���� ����
		//0�̸� ��ȣ�� ���ǵ� ���ڰ� �ƴϹǷ� ī��Ʈ ���ϰ� 0�̻��̸� ����� �� �߰�
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