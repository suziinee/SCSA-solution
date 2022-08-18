#include <stdio.h>

int r, c;
int arr[50 + 5][50 + 5];
int ans;

void input(void)
{
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++) {
		char ch[50 + 5];
		scanf(" %s", ch);
		for (int j = 0; j < c; j++) {
			if (ch[j] == '.') arr[i][j] = 0;
			else arr[i][j] = 1;
		}
	}
}

int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int shake(int y, int x)
{
	int ret = 0;
	int nx; int ny;
	for (int i = 0; i < 8; i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= c || ny >= r) continue;
		if (arr[ny][nx] == 1) ret++;
	}
	return ret;
}

void solve(void)
{
	int tmp; int max = -1;

	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			if (arr[y][x] == 1) {
				ans += shake(y, x);
			}
			else {
				tmp = shake(y, x);
				if (max < tmp) max = tmp;
			}
		}
	}

	if (max == -1) printf("%d", ans / 2);
	else printf("%d", ans / 2 + max);
}


void main(void)
{
	input();
	solve();
}