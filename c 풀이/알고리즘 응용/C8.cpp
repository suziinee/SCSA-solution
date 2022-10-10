#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 15
int R, C;
int ans;
char map[MAX][MAX];

struct AXIS { int y, x; };
AXIS blue, red;

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { -1, 0, 1, 0 };


inline bool check(int& nx, int& ny)
{
	return (nx < 0 || ny < 0 || nx >= C || ny >= R || map[ny][nx] == '#');
}

void dfs(int n, AXIS b, AXIS r)
{
	if (n > ans) return;
	if (b.x == r.x && b.y == r.y) return; //실패
	if (map[b.y][b.x] == 'H') return; //실패
	if (map[r.y][r.x] == 'H') { //성공
		if (ans > n) ans = n;
		return;
	}
	if (n == 10) return; //실패

	for (int d = 0; d < 4; d++) {
		int nrx = r.x + dx[d];
		int nry = r.y + dy[d];
		int nbx = b.x + dx[d];
		int nby = b.y + dy[d];

		bool chk_r = check(nrx, nry);
		bool chk_b = check(nbx, nby);

		if (!chk_r && !chk_b) {
			dfs(n + 1, { nby, nbx }, { nry, nrx });
		}
		else if (!chk_r && chk_b) {
			dfs(n + 1, b, { nry, nrx });
		}
		else if (chk_r && !chk_b) {
			dfs(n + 1, { nby, nbx }, r);
		}
		else {
			dfs(n + 1, b, r);
		}
	}
}

void input()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> R >> C;

		fill(&map[0][0], &map[MAX - 1][MAX], '\0');
		ans = 0x7fffffff;
		blue = {};
		red = {};

		for (int y = 0; y < R; y++) {
			for (int x = 0; x < C; x++) {
				cin >> map[y][x];
				if (map[y][x] == 'B') {
					blue.y = y; blue.x = x;
					map[y][x] = '.';
				}
				else if (map[y][x] == 'R') {
					red.y = y; red.x = x;
					map[y][x] = '.';
				}
			}
		}
		dfs(0, blue, red);
		if (ans == 0x7fffffff) cout << "-1\n";
		else cout << ans << "\n";
	}
}


int main()
{
	input();
	return 0;
}