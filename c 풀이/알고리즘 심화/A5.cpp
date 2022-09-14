#include <iostream>
#include <string>
using namespace std;

#define MAXN 100
int N;
string map_nor[MAXN];
string map_rg[MAXN];


void input()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> map_nor[i];
		map_rg[i] = map_nor[i];
		for (int j = 0; j < N; j++) {
			if (map_rg[i][j] == 'G') map_rg[i][j] = 'R';
		}
	}
}

void dfs(string *map, int y, int x, char col)
{
	static int dx[] = { 0, 1, 0, -1 };
	static int dy[] = { -1, 0, 1, 0 };

	map[y][x] = 'Z';

	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (map[ny][nx] != col) continue;

		dfs(map, ny, nx, col);
	}
}

void solve()
{
	int nor = 0; int rg = 0; //일반, 적록색맹

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map_nor[y][x] != 'Z') {
				dfs(map_nor, y, x, map_nor[y][x]);
				nor++;
			}
			if (map_rg[y][x] != 'Z') {
				dfs(map_rg, y, x, map_rg[y][x]);
				rg++;
			}
		}
	}

	cout << nor << " " << rg;
}


int main(void)
{
	input();
	solve();
	return 0;
}