#include <stdio.h>

int r;
int sq;
int top[1000 + 10]; //y값을 저장

void func(void)
{
	for (int x = 1; x <= r - 1; x++) {
		int y;
		for (y = r - 1; y >= 1; y--) {
			if ((x*x + y*y) <= r*r) break;
		}
		top[x] = y;
	}

	for (int i = 1; i <= r - 1; i++) {
		sq += top[i];
	}
}

void main(void)
{
	scanf("%d", &r);
	func();
	printf("\nans : %d", sq * 4);
}