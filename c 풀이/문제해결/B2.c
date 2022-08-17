#include <stdio.h>

int n;
char init[10 + 5][10 + 5];
int maze[10 + 5][10 + 5];
int check[10 + 5][10 + 5];
int dir[4]; 
int ans;

int off_dir(int nx, int ny)
{
	if (nx >= n) return 1;
	if (ny >= n) return 1;
	if (nx < 0) return 1;
	if (ny < 0) return 1;
	return 0;
}

void input(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %s", init[i]);
	}
	for (int i = 0; i < 4; i++) {
		scanf("%d", &dir[i]);
	}

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			maze[y][x] = init[y][x] - '0';
		}
	}
}

void func(void)
{
	int dx[5] = { 0, 0, -1, 0, 1 };
	int dy[5] = { 0, 1, 0, -1, 0 };

	int x = 0; int y = 0;
	check[0][0] = 1;
	int nx; int ny; int d = 0; //dir의 index
	int flag = 0;
	
	for (;;) {
		for (;;) { //올바른 nx, ny를 구해서 나오기
			nx = x + dx[dir[d]];
			ny = y + dy[dir[d]];
			if (check[ny][nx] == 1) {
				flag = 1; 
				break;
			}
			if (off_dir(nx, ny) == 1) {
				d = (d + 1) % 4;
			}
			else if (maze[ny][nx] == 1) {
				d = (d + 1) % 4;
			}
			else break;
		}
		if (flag == 1) break;
		else {
			check[ny][nx] = 1;
			ans++;
			x = nx; y = ny;
		}
	}
}


void main(void)
{
	input();
	func();
	printf("%d", ans);
}

