#include <stdio.h>

void func(int m)
{
	for (int i = 2; i*i <= m; i++) {
		if (m%i == 0) {
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
}

void main(void)
{
	int n; int m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %d", &m);
		func(m);
	}
}