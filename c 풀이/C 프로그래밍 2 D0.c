#include <stdio.h>

int m;
char a[100+10][100+10];
int p;
char pattern[100 + 10][100 + 10];
int ans;

void input(void)
{
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf(" %s", a[i]);
	}
	scanf("%d", &p);
	for (int i = 0; i < p; i++) {
		scanf(" %s", pattern[i]);
	}
}

int is_pattern(int x, int y)
{
	for (int i = x; i < x + p; i++) {
		for (int j = y; j < y + p; j++) {
			if (a[i][j] != pattern[i - x][j - y]) return 0;
		}
	}
	return 1;
}

void func(void)
{
	for (int i = 0; i <= m - p; i++) {
		for (int j = 0; j <= m - p; j++) {
			if (is_pattern(i, j)) ans += 1;
		}
	}
}

void main(void)
{
	input();
	func();
	printf("%d\n", ans);
}