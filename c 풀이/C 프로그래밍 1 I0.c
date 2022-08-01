#include <stdio.h>

int n;
int a[30000+10];
int medal[4] = {0, 1, 2, 0};

void slide(int medal_idx) //medal_idx부터 뒤로 한칸씩 밀어줌
{
	for (int i = 2; i >= medal_idx; i--) {
		medal[i + 1] = medal[i];
	}
}

void put(int medal_idx, int idx)
{
	switch (medal_idx) {
		case 2: slide(2); medal[2] = idx; break;
		case 1: slide(1); medal[1] = idx; break;
		case 0: slide(0); medal[0] = idx; break;
	}
}

void func(int idx)
{
	for (int i = 0; i < 3; i++) {
		if (a[idx] > a[medal[0]]) put(0, idx);
		else if ((a[idx] > a[medal[1]]) && (a[idx] < a[medal[0]])) put(1, idx);
		else if ((a[idx] > a[medal[2]]) && (a[idx] < a[medal[1]])) put(2, idx);
	}
}

void main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		func(i);
	}
	for (int i = 0; i < 3; i++) {
		printf("%d ", medal[i] + 1);
	}
}