#include <stdio.h>

int arr[5][5];
int nums[5][5];
typedef struct st {
	int x;
	int y;
} AXIS;
int ans; int b;

void input(void)
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &nums[i][j]);
		}
	}
}

int bingo(void)
{
	int ret = 0;
	//가로 먼저 확인
	for (int i = 0; i < 5; i++) {
		int breadth = 1;
		for (int j = 0; j < 5; j++) {
			if (arr[i][j] != 0) {
				breadth = 0; break;
			}
		}
		if (breadth) {
			ret++;
		}
	}

	//세로 확인
	for (int i = 0; i < 5; i++) {
		int height = 1;
		for (int j = 0; j < 5; j++) {
			if (arr[j][i] != 0) {
				height = 0; break;
			}
		}
		if (height) {
			ret++;
		}
	}

	//대각선 확인
	int tmp1 = 1; int tmp2 = 1;
	for (int i = 0; i < 5; i++) {
		if (arr[i][i] != 0) {
			tmp1 = 0; 
		}
		if (arr[i][4 - i] != 0) {
			tmp2 = 0; 
		}
	}
	if (tmp1) ret++;
	if (tmp2) ret++;
	return ret;
}

AXIS find(int num)
{
	AXIS ret;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[i][j] == num) {
				ret.x = j; ret.y = i;
				return ret;
			}
		}
	}
}

void solve(void)
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			AXIS axis = find(nums[i][j]);
			arr[axis.y][axis.x] = 0;
			if (bingo() >= 3) {
				ans = i * 5 + (j + 1);
				return;
			}
		}
	}
}


void main(void)
{
	input();
	solve();
	printf("%d", ans);
}