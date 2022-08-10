#include <stdio.h>

int n;
char ch = 'A';
char alpha[100 + 10][100 + 10];

int main(void)
{
	scanf("%d", &n);

	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			if (ch == 'Z') {
				alpha[j][i] = ch;
				ch = 'A';
			}
			else {
				alpha[j][i] = ch++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%c ", alpha[i][j]);
		}
		printf("\n");
	}

	return 0;
}