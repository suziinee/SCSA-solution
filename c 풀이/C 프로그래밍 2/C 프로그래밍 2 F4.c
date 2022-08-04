#include <stdio.h>

void Swap(char* a, char* b)
{
	int null_cnt = 0;
	char tmp;

	while (null_cnt < 2) {
		tmp = *a;
		*a = *b;
		*b = tmp;
		if (!*a) null_cnt++;
		if (!*b) null_cnt++;
		a++; b++;
	}
}

int main(void)
{
	char a[110], b[110];
	scanf("%s %s", a, b);
	Swap(a, b);
	printf("%s %s\n", a, b);
	return 0;
}
void main(void)
{
	char a[110], b[110];
	scanf("%s %s", a, b);
	Swap(a, b);
	printf("%s %s\n", a, b);
}