#include <stdio.h>

int arr[100 + 10][100 + 10];
int n;
int a, b;
int ans;

void color(int x, int y)
{
	for (int i = x; i < x + 10; i++) {
		for (int j = y; j < y + 10; j++) {
			if (arr[i][j] == 0) arr[i][j] = 1;
		}
	}
}

int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		color(a, b);
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (arr[i][j] == 1) ans++;
		}
	}
	printf("%d", ans);
	return 0;
}