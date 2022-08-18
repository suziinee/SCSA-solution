#include <stdio.h>

unsigned long long int n;

void func(void)
{
	unsigned long long int tmp = 0;
	unsigned long long int i = 1;
	for (;;) {
		tmp += i;
		if (n <= tmp) {
			printf("%d", i);
			return;
		}
		i++;
	}
}

void main(void)
{
	scanf("%llu", &n);
	func();
}
