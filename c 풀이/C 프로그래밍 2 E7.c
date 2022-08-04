#include <stdio.h>

void Reverse_Disp(char *ch)
{
	int cnt = 0;
	while (*ch) {
		ch++; cnt++;
	}
	ch -= 1;
	for (int i = 0; i < cnt; i++) {
		printf("%c", *ch--);
	}
}

int main(void)
{
	char a[110];
	scanf("%s", a);
	Reverse_Disp(a);
	return 0;
}