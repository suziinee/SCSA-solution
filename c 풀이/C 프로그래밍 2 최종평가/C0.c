#include <stdio.h>

int n; int m; int ans;
int answer[2][100 + 20];
int candi[100 + 10][50 + 10];
int flag[100 + 10];

void input(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &answer[0][i]);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &candi[i][j]);
		}
	}
}

void ans_rev(void)
{
	int rev[5] = { 0, 3, 4, 1, 2 };
	for (int i = 0; i < n; i++) {
		answer[1][n - 1 - i] = rev[answer[0][i]];
	}
}

void ans_copy(void)
{
	for (int i = 0; i < n; i++) {
		answer[0][i + n] = answer[0][i];
		answer[1][i + n] = answer[1][i];
	}
}

int compare(int can, int ans) //ans의 모든 경우에 대해서 can과 맞는지 비교
{
	for (int i = 0; i < n; i++) {
		int j = 0; int start = i;
		for (j = 0; j < n; j++, start++) {
			if (candi[can][j] != answer[ans][start]) break;
		}
		if (j == n) {
			flag[can] = 1;
			return 1;
		}
	}
	return 0;
}

void func(void)
{
	for (int i = 0; i < m; i++) {
		if (compare(i, 0)) ans++;
		if (compare(i, 1)) ans++;
	}
}

void output(void)
{
	printf("%d\n", ans);
	for (int i = 0; i < m; i++) {
		if (flag[i] == 1) {
			for (int j = 0; j < n; j++) printf("%d ", candi[i][j]);
			printf("\n");
		}
	}
}

void main(void)
{
	input();
	ans_rev();
	ans_copy();
	func();
	output();
}