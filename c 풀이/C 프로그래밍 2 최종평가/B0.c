#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int X;
char S[20 + 5];

int is_X(char *a, char *b)
{
	long long int x = atoll(a); long long int y = atoll(b);
	if ((x + y) == X) {
		printf("%lld+%lld=%lld", x, y, X);
		return 1;
	}
	return 0;
}

void func(void)
{
	int n = strlen(S);
	for (int i = 0; i < n - 1; i++) {
		char front[20 + 5] = { '\0' };
		char back[20 + 5] = { '\0' };
		strncpy(front, S, i+1);
		strncpy(back, &(S[i + 1]), n - (i + 1));
		if (is_X(front, back)) return;
	}
	printf("NONE");
}

void main(void)
{
	scanf("%s", S);
	scanf("%lld", &X);
	func();
}