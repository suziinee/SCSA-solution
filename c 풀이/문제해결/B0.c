#include <stdio.h>

int n;
int arr[100 + 10][100 + 10];
typedef struct _st {
	int x;
	int y;
} AXIS;

AXIS move(int x, int y) //왼쪽 위로 옮긴 좌표를 반환
{
	AXIS ret;
	if (x == 0) {
		ret.x = n - 1;
	}
	else {
		ret.x = x - 1;
	}

	if (y == 0) {
		ret.y = n - 1;
	}
	else {
		ret.y = y - 1;
	}
	return ret;
}

AXIS down(int x, int y) //아래 행의 좌표를 반환
{
	AXIS ret;
	if (y == n - 1) {
		ret.x = x;
		ret.y = 0;
	}
	else {
		ret.x = x;
		ret.y = y + 1;
	}
	return ret;
}

void func(void)
{
	AXIS tmp = { n / 2, 0 };

	for (int i = 1; i <= n*n; i++) {
		if (i == 1) {
			tmp.x = n / 2;
			tmp.y = 0;
		}
		else if ((i - 1)%n == 0) {
			tmp = down(tmp.x, tmp.y);
		}
		else {
			tmp = move(tmp.x, tmp.y);
		}
		arr[tmp.y][tmp.x] = i;
	}
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


void main(void)
{
	scanf("%d", &n);
	func();
	output();
}