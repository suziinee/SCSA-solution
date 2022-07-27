#include <stdio.h>

void func(int min, int max)
{
	for (int i = min; i <= max; i++) {
		int flag = 1;
		for (int j = 2; j*j <= i; j++) {
			if (i%j == 0) {
				flag = 0; break;
			}
		}
		if (flag) printf("%d\n", i);
	}
}

void main(void)
{
	int a, b;
	scanf("%d %d", &a, &b);

	if ((a <= 0) || (b <= 0)) {
		printf("Error!!\n");
	}
	else {
		a > b ? func(b, a) : func(a, b);
	}
}