#include <stdio.h>

int n;
int nums[1000 + 10];
int root[1000 + 10];
int max;

void input(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &nums[i]);
}

int calcul(int num)
{
	int ret = 0;
	while (num) {
		ret += num % 10; num /= 10;
	}
	return ret;
}

void digitroot(int idx)
{
	int n = nums[idx]; 
	int tmp = n;
	
	while (tmp >= 10) {
		tmp = calcul(tmp);
	}
	root[idx] = tmp;
}

void func(void)
{
	for (int i = 0; i < n; i++) {
		digitroot(i);
	}
	for (int i = 0; i < n; i++) {
		if (root[i] == root[max]) {
			max = nums[i] > nums[max] ? max : i; //둘 중에 작은 것
			continue;
		}
		if (root[i] > root[max]) max = i;
	}
}

void main(void)
{
	input();
	func();
	printf("%d", nums[max]);
}