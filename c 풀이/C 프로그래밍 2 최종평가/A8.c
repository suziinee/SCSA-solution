#include <stdio.h>

void main(void)
{
	int n;
	int sum;
	scanf("%d %d", &n, &sum);
	
	int total = (n * (n + 1)) / 2;
	int sub = total - sum;
	int m = (total - sum - 1) / 2;
	if (sub % 2 == 0) printf("Error");
	else if (m % 2 == 0) printf("Error");
	else if (m >= n) printf("Error");
	else printf("%d %d", m, m + 1);
}