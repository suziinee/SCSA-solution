#include <stdio.h>

int n;
int arr[150][150];
int w; int b;

void input(void)
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
}

void countpaper(int y, int x, int L)
{
	int tmp = arr[y][x];

	if (L == 1) {
		if (tmp == 0) w++;
		else b++;
		return;
	}

	for (int i = y; i < y + L; i++) {
		for (int j = x; j < x + L; j++) {
			if (arr[i][j] != tmp) {
				countpaper(y, x, L / 2);
				countpaper(y, x + L / 2, L / 2);
				countpaper(y + L / 2, x, L / 2);
				countpaper(y + L / 2, x + L / 2, L / 2);
				return;
			}
		}
	}

	if (tmp == 0) w++;
	else b++;
}


void main(void)
{
	input();
	countpaper(1, 1, n);
	printf("%d\n%d", w, b);
}