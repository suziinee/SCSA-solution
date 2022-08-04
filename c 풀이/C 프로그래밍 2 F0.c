#include <stdio.h>

char N;

int main(void)
{
	scanf("%c", &N);

	if (('a' <= N) && ('z' >= N)) {
		char start = 'a';
		while (start <= N) printf("%c", start++);
	}
	else if (('A' <= N) && ('Z' >= N)) {
		char start = N;
		while (start <= 'Z') printf("%c", start++);
	}
	else printf("Error");

	return 0;
}