#include <iostream>
#include <queue>
using namespace std;

int T;
char map[12][6];
int ans;

struct AXIS { int y; int x; };
queue<AXIS> q;


void bfs(int y, int x, char col, bool& flag)
{
	static int dx[] = { 0, 1, 0, -1 };
	static int dy[] = { -1, 0, 1, 0 };
	
	q = {};
	bool chk[12][6] = { false };

	q.push({ y, x });
	chk[y][x] = true;
	int cnt = 1;

	while (!q.empty()) {
		AXIS cur = q.front(); q.pop();

		for (int d = 0; d < 4; d++) {
			int nx = cur.x + dx[d];
			int ny = cur.y + dy[d];
			if (nx < 0 || ny < 0 || nx >= 6 || ny >= 12) continue;
			if (map[ny][nx] != col || chk[ny][nx]) continue;
			chk[ny][nx] = true;
			q.push({ ny, nx });
			cnt++;
		}
	}

	if (cnt >= 4) {
		flag = true;
		for (int y = 0; y < 12; y++) {
			for (int x = 0; x < 6; x++) {
				if (chk[y][x]) map[y][x] = '.';
			}
		}
	}
}

void pop_buyo(bool& flag)
{
	for (int y = 0; y < 12; y++) {
		for (int x = 0; x < 6; x++) {
			if (map[y][x] == '.') continue;
			bfs(y, x, map[y][x], flag);
		}
	}
}

void fall_buyo()
{
	for (int x = 0; x < 6; x++) {
		queue<char> cq;
		for (int y = 11; y >= 0; y--) {
			if (map[y][x] != '.') cq.push(map[y][x]);
			map[y][x] = '.';
		}
		for (int y = 11; y >= 0; y--) {
			if (!cq.empty()) {
				map[y][x] = cq.front(); cq.pop();
			}
			else {
				map[y][x] = '.';
			}
		}
	}
}

void solve()
{
	bool flag = false;
	while (true) {
		flag = false;
		pop_buyo(flag);
		if (!flag) break;
		ans++;
		fall_buyo();
	}
}

void input()
{
	cin >> T;
	for (int t = 0; t < T; t++) {

		for (int y = 0; y < 12; y++) {
			for (int x = 0; x < 6; x++) {
				cin >> map[y][x];
			}
		}
		ans = 0;
		solve();
		cout << ans << "\n";
	}
}


int main()
{
	input();
	return 0;
}