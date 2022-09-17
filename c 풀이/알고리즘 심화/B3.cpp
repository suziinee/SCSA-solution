#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

#define MAX 1000
int W, H;
string map[MAX];
int ans = 0;

struct AXIS { int y; int x; };
queue<AXIS> q;


void input()
{
	cin >> W >> H;
	for (int y = 0; y < H; y++) {
		cin >> map[y];
	}
}

void bfs(int y, int x)
{
	static const int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
	static const int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
	int cnt = 0;

	q = {};
	q.push({ y, x });
	map[y][x] = '0';
	cnt++;

	while (!q.empty()) {
		AXIS data = q.front(); q.pop();

		for (int d = 0; d < 8; d++) {
			int nx = data.x + dx[d];
			int ny = data.y + dy[d];

			if (nx < 0 || ny < 0 || nx >= W || ny >= H) continue;
			if (map[ny][nx] == '0') continue;

			q.push({ ny, nx });
			map[ny][nx] = '0';
			cnt++;
		}
	}

	if (cnt > ans) ans = cnt;
}

void solve()
{
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			if (map[y][x] == '1') bfs(y, x);
		}
	}
	cout << ans;
}


int main(void)
{
	input();
	solve();
	return 0;
}