#include <stdio.h>

int n;

void print_star(int num)
{
	for (int i = 0; i < num; i++)
		printf("*");
	printf("\n");
}

void func(int num) //1, 2, ..num, num, ... 2, 1로 별 찍어주는 함수
{
	print_star(num);
	if (num == n) return;
	func(num + 1);
	print_star(num);
}

void main(void)
{
	scanf("%d", &n);
	func(1);
}
