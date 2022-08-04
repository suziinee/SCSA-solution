#include <stdio.h>

char d[100];
char s[10];

int count(char* a)
{
	int n = 0;
	while (a[n]) n++;
	return n;
}

//pos 인덱스부터 s의 문자열 개수만큼 만큼 만큼 뒤로 밀기
void slide(char* a, char* b, int pos)
{
	int len_a = count(a);
	int len_b = count(b);
	for (int i = len_a - 1; i >= pos; i--) {
		a[i + len_b] = a[i];
	}
}

char* str_insert(char* d, char* s, int pos)
{
	slide(d, s, pos);
	while (*s) {
		d[pos++] = *s++;
	}
	return d;
}

int main(void)
{
	int pos;
	char * sol;

	// 입력받는 부분
	scanf("%s", d);
	scanf("%s", s);
	scanf("%d", &pos);

	sol = str_insert(d, s, pos - 1);

	// 출력하는 부분
	printf("%s", sol);

	return 0;
}