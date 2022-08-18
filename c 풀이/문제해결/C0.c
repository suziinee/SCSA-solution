#include <stdio.h>

int n;
int arr[150][150];
int white; int blue;
typedef struct st {
	int x1; int y1; 
	int x2; int y2;
	int x3; int y3;
	int x4; int y4;
} D;
void func(int x, int y, int L);

void input(void)
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
}

void check(int x, int y, int L)
{
	if (L == 1) {
		if (arr[y][x] == 0) white++;
		else blue++;
		return;
	}
	else {
		int tmp = arr[y][x];
		for (int i = y; i < y + L; i++) {
			for (int j = x; j < x + L; j++) {
				if (tmp != arr[i][j]) {
					func(x, y, L);
					return;
				}
			}
		}
		if (tmp == 0) white++;
		else blue++;
	}
}

D divide(int x, int y, int L) //(y, x)로 시작해서 L개씩 4개로 쪼개줌
{
	D d;
	d.x1 = x; d.y1 = y;
	d.x2 = x + L; d.y2 = y;
	d.x3 = x; d.y3 = y + L;
	d.x4 = x + L; d.y4 = y + L;
	return d;
}

void func(int x, int y, int L) //L개를 쪼개고 체크해주는 함수
{
	D tmp = divide(x, y, L / 2);
	check(tmp.x1, tmp.y1, L/2);
	check(tmp.x2, tmp.y2, L/2);
	check(tmp.x3, tmp.y3, L/2);
	check(tmp.x4, tmp.y4, L/2);
}


void main(void)
{
	input();
	check(1, 1, n);
	printf("%d\n%d", white, blue);
}