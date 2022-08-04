#include <stdio.h>

char tmp;

void copy(char* before, char* after, int start)
{
	for (start; before[start] != '\0'; start++) {
		after[start] = before[start];
	}
	after[start] = before[start];
}

void Swap(char* a, char* b)
{
	int null_cnt = 0;
	int i;

	for (i = 0; ; i++) {
		tmp = b[i];
		b[i] = a[i];
		a[i] = tmp;
		if (a[i] == '\0' || b[i] == '\0') break;
	}
	if (a[i] == '\0' && b[i] == '\0') return;
	else if (a[i] == '\0') { //b가 더 짦음
		copy(a, b, i + 1);
	}
	else if (b[i] == '\0') { //a가 더 짧음
		copy(b, a, i + 1);
	}
}

void main(void)
{
	char a[110], b[110];
	scanf("%s %s", a, b);
	Swap(a, b);
	printf("%s %s\n", a, b);
}