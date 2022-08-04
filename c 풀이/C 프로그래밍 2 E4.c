#include <stdio.h>

char S1[100 + 100 + 10] = "0123456789";
char S2[100 + 10];
int N;

char *strncat(char *dest, const char *src, unsigned int n)
{
	for (;;) {
		if (!*dest) break;
		dest++;
	}

	for (int i = 0; i < n; i++) {
		*dest = *src;
		if (!*src) break;
		dest++; src++;
	}
	if (*src) *dest = '\0';

	return dest;
}

void main(void)
{
	scanf("%s", S1);
	scanf("%s", S2);
	scanf("%d", &N);

	strncat(S1, S2, N);

	printf("%s", S1);
}
