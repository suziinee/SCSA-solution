#include <stdio.h>

int n;
int arr[100 + 10][100 + 10];
typedef struct st {
	int x;
	int y;
} AXIS;
AXIS a[100 + 10];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
int ans;

void input(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i].x, &a[i].y);
	}
}

void color(int x, int y)
{
	for (int i = y; i < y + 10; i++) {
		for (int j = x; j < x + 10; j++) {
			if (arr[i][j] == 0) arr[i][j] = 1;
		}
	}
}

void check(int x, int y)
{
	int nx; int ny;
	for (int i = 0; i < 4; i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= 100 || ny >= 100) {
			ans++;
			continue;
		}
		if (arr[ny][nx] == 0) {
			ans++;
			continue;
		}
	}
}

void func(void)
{
	for (int i = 0; i < n; i++) {
		color(a[i].x, a[i].y);
	}

	for (int y = 0; y < 100; y++) {
		for (int x = 0; x < 100; x++) {
			if (arr[y][x] == 1) check(x, y);
		}
	}
}


void main(void)
{
	input();
	func();
	printf("%d", ans);
}
