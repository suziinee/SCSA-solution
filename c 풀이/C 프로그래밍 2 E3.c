#include <stdio.h>

int N;
char S1[100 + 10];
char S2[100 + 10];

int strncmp(const char *s1, const char *s2, unsigned int n)
{
	for (int i = 0; i < n; i++) {
		if ((*s1) > (*s2)) return 1;
		if ((*s1) < (*s2)) return -1;
		if (((*s1) == (*s2)) && (!(*(s1+1)) && !(*(s2+1)))) return 0;
		s1++; s2++;
	}

}

void main(void)
{
	int ret;

	scanf("%d", &N);
	scanf("%s", S1);
	scanf("%s", S2);

	ret = strncmp(S1, S2, N);

	if (ret > 0) printf("B");
	else if (ret < 0) printf("S");
	else printf("E");
}