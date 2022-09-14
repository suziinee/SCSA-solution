#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 100
int N;
int map[MAXN][MAXN];
int chk[MAXN][MAXN];
int min_ = 101; int max_ = -1;

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { -1, 0, 1, 0 };


void input()
{
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			if (map[y][x] < min_) min_ = map[y][x];
			if (map[y][x] > max_) max_ = map[y][x];
		}
	}
}

void flood_fill(int y, int x, int h) //0인 곳을 1로 만들기
{
	chk[y][x] = 1;

	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (map[ny][nx] > h) continue;
		if (chk[ny][nx]) continue;

		flood_fill(ny, nx, h);
	}
}

void dfs(int y, int x) //0인 곳을 카운트
{
	chk[y][x] = 1;

	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (chk[ny][nx]) continue;

		dfs(ny, nx);
	}
}

void solve()
{
	int ans = 1; 

	for (int h = min_; h <= max_; h++) {
		fill(&chk[0][0], &chk[MAXN - 1][MAXN], 0);
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (map[y][x] <= h && chk[y][x] == 0) flood_fill(y, x, h);
			}
		}

		int cnt = 0;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (chk[y][x] == 0) { dfs(y, x); cnt++; }
			}
		}

		if (cnt > ans) ans = cnt;
	}

	cout << ans;
}


int main(void)
{
	input();
	solve();
	return 0;
}