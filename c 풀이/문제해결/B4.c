#include <stdio.h>

int n; int p;

void func(void)
{
	if (p <= n / 2) {
		if (p % 2 == 1) {
			printf("%d %d %d", p + 1, n - p, n - p + 1);
		}
		else {
			printf("%d %d %d", p - 1, n + 1 - p, n + 2 - p);
		}
	}
	else {
		if (p % 2 == 1) {
			printf("%d %d %d", n - p, n - p + 1, p + 1);
		}
		else {
			printf("%d %d %d", n + 1 - p, n + 2 - p, p - 1);
		}
	}
}


void main(void)
{
	scanf("%d %d", &n, &p);
	func();
}
