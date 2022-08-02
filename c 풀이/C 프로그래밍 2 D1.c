#include <stdio.h>

int map[2][50 + 10][50 + 10];
int cur;
int n;

void output(void)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", map[cur][i][j]);
		}
		printf("\n");
	}
}

//cur에서 (cur+1)%2로
void rotation(void)
{
	int after = (cur + 1) % 2;
	int y = n - 1;
	for (int i = 0; i < n; i++) {
		int x = 0;
		for (int j = 0; j < n; j++) {
			map[after][x][y] = map[cur][i][j];
			x += 1;
		}
		y -= 1;
	}
	cur = after;
}

void main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[cur][i][j]);
		}
	}
	int tmp;
	for (;;) {
		scanf("%d", &tmp);
		if (!tmp) break;
		for (int i = 0; i < (tmp / 90); i++) {
			rotation();
		}
		output();
	}
}
