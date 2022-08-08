#include <stdio.h>

int n;
int score[4][4]; //i번 후보에 대한 j점의 개수
int sum[4];
int max[4];
int max_idx;

void input(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp1, tmp2, tmp3;
		scanf("%d %d %d", &tmp1, &tmp2, &tmp3);
		sum[1] += tmp1; sum[2] += tmp2; sum[3] += tmp3;
		score[1][tmp1] += 1; score[2][tmp2] += 1; score[3][tmp3] += 1;
	}
}

int sum_max(void) //max가 몇명 있는지 리턴, max가 있는 index에는 표시를 해줌
{
	int max_cnt = 0;
	for (int i = 1; i <= 3; i++) {
		if (sum[i] > sum[max_idx]) max_idx = i;
	}
	for (int i = 1; i <= 3; i++) {
		if (sum[i] == sum[max_idx]) {
			max[i] = 1;
			max_cnt++;
		}
	}
	return max_cnt;
}

int compare_two(int a, int b)
{
	for (int i = 3; i >= 2; i--) {
		if (score[a][i] > score[b][i]) return a;
		if (score[a][i] < score[b][i]) return b;
	}
	return -1;
}

int compare_three(void)
{
	for (int i = 3; i >= 2; i--) { //312 123 213 132 231 321
		if (score[1][i] > score[2][i]) {
			if (score[3][i] > score[1][i]) return 3;
			if (score[2][i] > score[3][i]) return 1;
		}
		else if (score[1][i] > score[3][i]) {
			if (score[2][i] > score[1][i]) return 2;
			if (score[3][i] > score[2][i]) return 1;
		}
		else if ((score[2][i] > score[3][i]) && (score[3][i] > score[1][i])) return 2;
		else if ((score[3][i] > score[2][i]) && (score[2][i] > score[1][i])) return 3;
	}
	return -1;
}

void func(void)
{
	int m = sum_max();
	if (m == 1) {
		printf("%d %d", max_idx, sum[max_idx]);
	}
	else if (m == 2) {
		int tmp;
		if (sum[1] == sum[2]) tmp = compare_two(1, 2);
		else if (sum[1] == sum[3]) tmp = compare_two(1, 3);
		else if (sum[2] == sum[3]) tmp = compare_two(2, 3);

		if (tmp == -1) printf("0 %d", sum[max_idx]);
		else printf("%d %d", tmp, sum[tmp]);
	}
	else {
		int tmp = compare_three();
		if (tmp == -1) printf("0 %d", sum[max_idx]);
		else printf("%d %d", tmp, sum[tmp]);
	}
}

void main(void)
{
	input();
	func();
}