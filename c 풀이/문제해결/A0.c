#include <stdio.h>

int num[5];
int clock;
int ans = 1;

int make_clock(int num)
{
	int tmp[4] = { 0 }; int cpy = num;
	for (int i = 3; i >= 0; i--) {
		tmp[i] = cpy % 10;
		if (tmp[i] == 0) return 0;
		cpy /= 10;
	}

	int candi[4] = { 0 };
	candi[0] = num;

	for (int i = 0; i < 3; i++) {
		candi[i + 1] = (candi[i] - tmp[i] * 1000) * 10 + tmp[i];
	}

	int min = 0;
	for (int i = 0; i < 4; i++) {
		if (candi[i] < candi[min]) min = i;
	}
	
	return candi[min];
}

void func(void)
{
	clock = 1000 * num[0] + 100 * num[1] + 10 * num[2] + num[3];
	clock = make_clock(clock);
	for (int i = 1111; i < clock; i++) {
		if (make_clock(i) == i) ans++;
	}
}


void main(void)
{
	for (int i = 0; i < 4; i++) {
		scanf("%d", &num[i]);
	}
	func();
	printf("%d", ans);
}