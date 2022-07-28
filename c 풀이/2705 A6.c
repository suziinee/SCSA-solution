#include <stdio.h>

#define ASIZE(arr) sizeof(arr)/sizeof((arr)[0])
int a[20];

void swap(int x, int y)
{
	int tmp;
	tmp = a[y];
	a[y] = a[x];
	a[x] = tmp;
}

void func(int start, int end)
{
	int min_idx = start;
	for (int i = start+1; i <= end; i++) {
		if (a[i] < a[min_idx]) min_idx = i;
	}
	swap(min_idx, start);
}

void main(void)
{
	for (int i = 0; i < ASIZE(a); i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < ASIZE(a) - 1; i++) {
		func(i, ASIZE(a) - 1);
	}
	for (int i = 0; i < ASIZE(a); i++) {
		printf("%d ", a[i]);
	}
}