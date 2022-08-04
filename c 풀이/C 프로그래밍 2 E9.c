#include <stdio.h>

char ans[110];

char* str_insert(char* d, char* s, int pos)
{
	int i = 0;

	for (i; i < pos; i++) {
		ans[i] = *d++;
	}
	for (i; *s != '\0'; i++) {
		ans[i] = *s++;
	}
	for (i; *d != '\0'; i++) {
		ans[i] = *d++;
	}
	return ans;
}

void main(void)
{
	char d[100];
	char s[10];
	int pos;
	char * sol;

	// 입력받는 부분
	scanf("%s", d);
	scanf("%s", s);
	scanf("%d", &pos);

	sol = str_insert(d, s, pos - 1);

	// 출력하는 부분
	printf("%s", sol);
}