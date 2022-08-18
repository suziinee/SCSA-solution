#include <stdio.h>

int n;
int flag = 0;

void draw(int num) //num개의 별을 그려줌
{
	if (num == 0) return;
	if (num == n + 1) {
		flag = 1;
		draw(num - 2);
		return;
	}

	if (flag == 0) {
		for (int i = 0; i < num; i++) printf("*");
		printf("\n");
		draw(num + 1);
	}
	else if (flag == 1) {
		for (int i = 0; i < num; i++) printf("*");
		printf("\n");
		draw(num - 1);
	}
}


void main(void)
{
	scanf("%d", &n);
	draw(1);
}
