#include <stdio.h>
#include <math.h>

void main(void)
{
	int n;
	scanf("%d", &n);
	int square = pow(2, n);
	printf("%d", (square + 1)*(square + 1));
}