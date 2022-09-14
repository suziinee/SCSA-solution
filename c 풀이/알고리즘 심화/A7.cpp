#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 100
int R, C;
int map[MAX][MAX];

struct AXIS { int y; int x; };
queue<AXIS> q;
bool chk[MAX][MAX];


void input()
{
	cin >> R >> C;
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			cin >> map[y][x];
		}
	}
}

void bfs(int y, int x) //공기와 닿는 부분을 2로 변경
{
	static int dx[] = { 0, 1, 0, -1 };
	static int dy[] = { -1, 0, 1, 0 };

	q.push({ y, x });
	chk[y][x] = true;

	while (!q.empty()) {
		AXIS data = q.front(); q.pop();
		
		for (int d = 0; d < 4; d++) {
			int nx = data.x + dx[d];
			int ny = data.y + dy[d];

			if (nx < 0 || ny < 0 || nx >= C || ny >= R) continue;
			if (chk[ny][nx]) continue;

			if (map[ny][nx] == 0) {
				chk[ny][nx] = true;
				q.push({ ny, nx });
			}
			else if (map[ny][nx] == 1) {
				map[ny][nx] = 2;
			}
		}
	}
}

void melt()
{
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (map[y][x] == 2) map[y][x] = 0;
		}
	}
}

int check() //1이 있으면 1, 2만 있으면 짝수 리턴
{
	int cnt = 0;
	for (int y = 1; y < R - 1; y++) {
		for (int x = 1; x < C - 1; x++) {
			if (map[y][x] == 1) return 1;
			if (map[y][x] == 2) cnt += 2;
		}
	}
	return cnt;
}

void solve()
{
	int t = 0; int cnt = 0;

	while (true) {
		fill(&chk[0][0], &chk[MAX - 1][MAX], 0);
		bfs(0, 0);
		bfs(0, C - 1);
		bfs(R - 1, 0);
		bfs(R - 1, C - 1);
		t++;

		int c = check();
		if (c == 1) {
			melt();
		}
		else { //마지막 단계
			cnt = c / 2;
			break;
		}
	}

	cout << t << "\n" << cnt;
}


int main(void)
{
	input();
	solve();
	return 0;
}