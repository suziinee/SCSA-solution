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
const int dy[] = { -1, 0, 1, 0 };
void solve()
{
	int dir = 0;
	AXIS tmp = { n / 2, n / 2 };

	for (int i = 1; i <= n * n; i++) {
		arr[tmp.y][tmp.x] = i;
		
		while (true) {
			const int new_dir[] = { 3, 0, 1, 2 };

			AXIS next;
			next.x = tmp.x + dx[dir];
			next.y = tmp.y + dy[dir];

			if (arr[next.y][next.x] != 0) {
				dir = new_dir[dir];
			}
			else {
				tmp = next;
				dir = (dir + 1) % 4;
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
