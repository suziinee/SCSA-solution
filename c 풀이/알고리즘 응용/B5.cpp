#include <iostream>
#include <vector>
using namespace std;

#define MAXN 500
int N;
int M; //돌아다녀야 하는 수 
int min_h, max_h;

int map[MAXN][MAXN];
bool visited[MAXN][MAXN]; //매 높이마다 방문 여부


void input()
{
	cin >> N;
	if (N % 2) M = ((N * N) / 2) + 1;
	else M = (N * N) / 2;

	min_h = 0x7fffffff; max_h = -1;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			if (map[y][x] < min_h) min_h = map[y][x];
			if (map[y][x] > max_h) max_h = map[y][x];
		}
	}
}

void dfs(int y, int x, const int& h, int& cnt) //flood fill 진행
{
	static int dx[] = { 0, 1, 0, -1 };
	static int dy[] = { -1, 0, 1, 0 };

	visited[y][x] = true;
	cnt++;

	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (abs(map[ny][nx] - map[y][x]) > h) continue;
		if (visited[ny][nx]) continue;
		dfs(ny, nx, h, cnt);
	}
}

void solve()
{
	int ans; int mid;
	int st = 0; int en = max_h - min_h;

	while (st <= en) {
		mid = (st + en) / 2; //정해진 높이
		fill(&visited[0][0], &visited[MAXN - 1][MAXN], false);

		int max_cnt = -1;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (visited[y][x]) continue;
				int cnt = 0;
				dfs(y, x, mid, cnt);
				max_cnt = max(max_cnt, cnt);
			}
		}

		if (max_cnt >= M) {
			ans = mid;
			en = mid - 1; //더 최소를 찾으러 가기
		}
		else {
			st = mid + 1;
		}
	}
	cout << ans;
}


int main()
{
	input();
	solve();
	return 0;
}