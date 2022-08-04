#include <stdio.h>

int N;
char S1[100 + 10];
char S2[100 + 10] = "0123456789";

char *strncpy(char *dest, const char *src, unsigned int n)
{
	int idx = -1;
	for (int i = 0; i < n; i++) {
		*dest = *src;
		if (!*src) {
			idx = i; break;
		}
		dest++; src++;
	}
	
	if (idx != -1) {
		for (int i = idx; i < n; i++) {
			*dest = '\0';
		}
	}
	return dest;
}

void main(void)
{
	scanf("%d", &N);
	scanf("%s", S1);
	strncpy(S2, S1, N);
	printf("%s", S2);
}
