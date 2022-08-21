#include <stdio.h>

int n, m;
int map[10 + 5][10 + 5];

void input(void)
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
}

int donut(int y, int x) //(y, x)부터 시작하는 도넛의 합을 리턴
{
	int ret = 0;
	for (int i = y; i < y + m; i++) {
		for (int j = x; j < x + m; j++) {
			if (i == y) {
				ret += map[i][j]; continue;
			}
			if (j == x) {
				ret += map[i][j]; continue;
			}
			if (i == (y + m - 1)) {
				ret += map[i][j]; continue;
			}
			if (j == (x + m - 1)) {
				ret += map[i][j]; continue;
			}
		}
	}
	return ret;
}

void solve(void)
{
	int max = -1;
	for (int y = 0; y <= n - m; y++) {
		for (int x = 0; x <= n - m; x++) {
			int d = donut(y, x);
			if (d > max) max = d;
		}
	}
	printf("%d", max);
}


int main(void)
{
	input();
	solve();
	return 0;
}