#include <stdio.h>

int n;
int b;
int min, max;

void calcul(void)
{
	int month = n - 1;
	if (b % month == 0) {
		max = b / month * n;
		min = max - 1;
		return;
	}
	else {
		max = b + (b / month);
		min = max;
		return;
	}
}

int main(void)
{
	scanf("%d %d", &n, &b);
	calcul();
	printf("%d %d", min, max);
	return 0;
}