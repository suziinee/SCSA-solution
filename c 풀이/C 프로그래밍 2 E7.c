#include <stdio.h>

void Reverse_Disp(char *ch)
{
	char *p = ch;
	while (*ch) ch++;
	ch -= 1;
	while (p <= ch) {
		printf("%c", *ch);
		ch--;
	}
}

int main(void)
{
	char a[110];
	scanf("%s", a);
	Reverse_Disp(a);
	return 0;
}