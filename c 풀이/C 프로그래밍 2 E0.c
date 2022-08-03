#include <stdio.h>

int str_comp(const char *a, const char *b)
{
	int idx = 0;
	for (;;) {
		
		if (!a[idx] && !b[idx]) {
			return 0;
		}
		else {
			if (a[idx] > b[idx]) return 1;
			if (a[idx] < b[idx]) return -1;
			idx++;
		}
	}
}

void main(void)
{
	printf("%d\n", str_comp("ABC", "BC"));
	printf("%d\n", str_comp("ABC", "AC"));
	printf("%d\n", str_comp("ABC", "AB"));
	printf("%d\n", str_comp("abc", "ABC"));
	printf("%d\n", str_comp("ab", " "));
	printf("%d\n", str_comp("A", "AB"));
	printf("%d\n", str_comp("ABC", "ABC"));
}