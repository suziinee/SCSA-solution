#include <stdio.h>

int n;
int a[50 + 10][50 + 10];
int b[50 + 10][50 + 10];
int rotate;
void input(void);
void output(void);
void rotation90(void);
void btoa(void);

void input(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (;;) {
		scanf("%d", &rotate);
		if (rotate == 0) break;
		for (int i = 1; i <= (rotate / 90); i++) {
			rotation90();
			btoa();
		}
		output();
	}
}

void output(void)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
}

void rotation90(void)
{
	int y = n - 1;
	for (int i = 0; i < n; i++) {
		int x = 0;
		for (int j = 0; j < n; j++) {
			b[x][y] = a[i][j];
			x += 1;
		}
		y -= 1;
	}
}

void btoa(void)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = b[i][j];
		}
	}
}

void main(void)
{
	input();
}