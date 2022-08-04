#include <stdio.h>

char d[100];
char s[10];

int count(char* a)
{
	int n = 0;
	while (a[n]) n++;
	return n;
}

//d의 idx 자리에 ch를 넣고 한칸씩 뒤로 밀어서 리턴
void slide(char* a, char ch, int idx)
{
	int n = count(a);
	for (int i = n; i > idx; i--) {
		a[i] = a[i - 1];
	}
	a[idx] = ch;
}

char * str_insert(char* d, char* s, int pos)
{
	int s_len = count(s);
	for (int i = 0; i < s_len; i++) {
		slide(d, s[i], pos);
		pos++;
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