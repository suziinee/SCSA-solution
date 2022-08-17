#include <stdio.h>

int r, c; 
int ans; int max = -1;
typedef struct st {
	int x; int y; int ex;
	int chk[8];
} P;
P arr[50 + 5][50 + 5];
int person;
int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

void input(void)
{
	scanf("%d %d", &r, &c);
	char ch[50 + 5];
	for (int y = 0; y < r; y++) {
		scanf(" %s", ch);
		for (int x = 0; x < c; x++) {
			if (ch[x] == '.') {
				arr[y][x].x = x; arr[y][x].y = y; arr[y][x].ex = 0;
			}
			else if (ch[x] == 'o') {
				arr[y][x].x = x; arr[y][x].y = y; arr[y][x].ex = 1;
				person++;
			}
		}
	}
}

int check(P p)
{
	int nx; int ny; int ret = 0;
	for (int i = 0; i < 8; i++) {
		nx = p.x + dx[i];
		ny = p.y + dy[i];
		if (p.chk[i] == 1) continue;
		if (arr[ny][nx].ex == 0) continue;
		if (nx < 0 || ny < 0 || nx >= c || ny >= r) continue;
		p.chk[i] = 1;
		arr[ny][nx].chk[(i + 4) % 8] = 1;
		ret++;
	}
	return ret;
}

void func(void)
{
	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			if (arr[y][x].ex == 1) {
				ans += check(arr[y][x]);
			}
		}
	}

	if (person == (r*c)) return;

	int tmp = 0;
	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			if (arr[y][x].ex == 0) {
				tmp = check(arr[y][x]);
				if ((ans + tmp) > max) max = ans + tmp;
			}
		}
	}
	ans = max;
}


void main(void)
{
	input();
	func();
	printf("%d", ans);
}
