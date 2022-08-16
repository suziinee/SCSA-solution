#include <stdio.h>

int num[5];
int clock;
int ans = 1;
int clock_hash[10000 + 10];
int nonclock_hash[10000 + 10];

void hash_clock(int num) //hash에 없는 숫자들을 hash에 넣어주는 함수
{
	int tmp[4] = { 0 }; int cpy = num;
	for (int i = 3; i >= 0; i--) {
		tmp[i] = cpy % 10;
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
	
	for (int i = 0; i < 4; i++) {
		if (i == min) clock_hash[candi[i]] = 1;
		else nonclock_hash[candi[i]] = 1;
	}
}

void make_clock(void)
{
	clock = 1000 * num[0] + 100 * num[1] + 10 * num[2] + num[3];
	int candi[4] = { 0 }; candi[0] = clock;
	for (int i = 0; i < 3; i++) {
		candi[i + 1] = (candi[i] - num[i] * 1000) * 10 + num[i];
	}
	for (int i = 0; i < 4; i++) {
		if (clock > candi[i]) clock = candi[i];
	}
}

void func(void)
{
	make_clock();
	for (int i = 1111; i < clock; i++) {
		if (clock_hash[i]) ans++;
		else if (nonclock_hash[i]) continue;
		else {
			hash_clock(i);
			if (clock_hash[i]) ans++;
			else if (nonclock_hash[i]) continue;
		}
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