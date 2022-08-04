#include <stdio.h>

char s[50 + 10];

int main(void)
{
	// 입력받는 부분
	char *p = s + 1;
	gets(p);

	while (*p) p++;
	p -= 1;
	while (*p) printf("%c", *p--);

	return 0;
}