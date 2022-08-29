#include <iostream>
#include <stdio.h>
using namespace std;

int n;
int arr[500][500];
struct AXIS {
	int x; int y;
};

void input()
{
	cin >> n;
}

void output()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };
void solve()
{
	int dir = 0;
	AXIS tmp = { 0, 0 };

	for (int i = n * n; i >= 1; i--) {
		arr[tmp.y][tmp.x] = i;
		
		if (i == 1) return;

		while (true) {
			AXIS next;
			next.y = tmp.y + dy[dir];
			next.x = tmp.x + dx[dir];
			if (next.y < 0 || next.x < 0 || next.y >= n || next.x >= n || arr[next.y][next.x] != 0) {
				dir = (dir + 1) % 4;
			}
			else {
				tmp = next;
				break;
			}
		}
	}
}

int main()
{
	input();
	solve();
	output();
	return 0;
}
