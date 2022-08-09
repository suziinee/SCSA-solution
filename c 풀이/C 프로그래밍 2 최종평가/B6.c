#include <stdio.h>

long long int a, b, c;

long long int min(void)
{
	long long int m = a > b ? b : a;
	m = m > c ? c : m;
	return m;
}

void main(void)
{
	scanf("%lld %lld %lld", &a, &b, &c);
	long long int n = min();
	long long int max = -1;
	for (long long int i = 1; i <= n; i++) {
		if (((a%i) == (b%i)) && ((b%i) == (c%i))) {
			if (max < i) max = i;
		}
	}
	printf("%d", max);
}