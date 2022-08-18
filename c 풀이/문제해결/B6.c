#include <stdio.h>
#include <math.h>

unsigned long long int n;

void func(void)
{
	unsigned long long int k = (unsigned long long int)(-1 + sqrt(1 + 8 * n)) / 2;
	unsigned long long int tmp = (k*(k + 1)) / 2;
	if (tmp < n) k++;
	printf("%llu", k);
}

void main(void)
{
	scanf("%llu", &n);
	func();
}