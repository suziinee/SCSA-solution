#include <stdio.h>

int n;
int arr[100 + 10][100 + 10];
int hash[100 + 10][100 + 10];
int dir;

int off_dir(int nx, int ny)
{
	if (nx >= n) return 0;
	if (ny >= n) return 0;
	if (nx < 0) return 0;
	if (ny < 0) return 0;
	return 1;
}

void output(void)
{
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			printf("%d ", arr[y][x]);
		}
		printf("\n");
	}
}

void func(void)
{
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };

	int x = -1; int y = 0;
	int nx; int ny;

	for (int i = 1; i <= n*n; i++) {
		nx = x + dx[dir];
		ny = y + dy[dir];
		if (off_dir(nx, ny) == 0) {
			dir = (dir + 1) % 4;
			nx = x + dx[dir];
			ny = y + dy[dir];
		}
		else if (hash[ny][nx] == 1) {
			dir = (dir + 1) % 4;
			nx = x + dx[dir];
			ny = y + dy[dir];
		}
		arr[ny][nx] = i;
		hash[ny][nx] = 1;
		x = nx; y = ny;
	}
}


void main(void)
{
	scanf("%d", &n);
	func();
	output();
}


