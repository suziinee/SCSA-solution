#include <stdio.h>

typedef struct st {
	int x;
	int y;
} POS;
POS arr[26];
int nums[25];
int bingo;
int map[5][5];

void input(void)
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			int a;
			scanf("%d", &a);
			arr[a].x = j; arr[a].y = i; 
		}
	}
	for (int i = 0; i < 25; i++) scanf("%d", &nums[i]);
}

void check(int y, int x)
{
	int row = 1;
	for (int i = 0; i < 5; i++) {
		if (map[y][i] != 1) {
			row = 0; break;
		}
	}
	if (row) bingo++;

	int col = 1;
	for (int i = 0; i < 5; i++) {
		if (map[i][x] != 1) {
			col = 0; break;
		}
	}
	if (col) bingo++;

	if (x == y) {
		int right = 1;
		for (int i = 0; i < 5; i++) {
			if (map[i][i] != 1) {
				right = 0; break;
			}
		}
		if (right) bingo++;
	}
	if (x + y == 4) {
		int left = 1;
		for (int i = 0; i < 5; i++) {
			if (map[i][4 - i] != 1) {
				left = 0; break;
			}
		}
		if (left) bingo++;
	}
}

void solve(void)
{
	for (int i = 0; i < 25; i++) {
		int x = arr[nums[i]].x; 
		int y = arr[nums[i]].y;
		map[y][x] = 1;
		check(y, x);
		if (bingo >= 3) {
			printf("%d", i + 1);
			return;
		}
	}
}


void main(void)
{
	input();
	solve();
}