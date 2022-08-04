#include <stdio.h>

char str[10000 + 10];
int  cnt_KOI, cnt_IOI;

void search_KOI(char* a)
{
	if ((*(a + 1) == 'O') && (*(a + 2) == 'I')) cnt_KOI++;
}

void search_IOI(char* a)
{
	if ((*(a + 1) == 'O') && (*(a + 2) == 'I')) cnt_IOI++;
}

void func(char* p)
{
	while (*p) {
		if ((*p) == 'K') search_KOI(p);
		if ((*p) == 'I') search_IOI(p);
		p++;
	}
}

int main(void)
{
	// 입력받는 부분
	gets(str);

	func(str);

	// 출력하는 부분
	printf("%d\n%d", cnt_KOI, cnt_IOI);

	return 0;
}