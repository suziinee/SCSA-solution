#include <iostream>
#include <string>
using namespace std;

#define MAXN 100
int N;
string map[MAXN];


void input()
{
	cin >> N;
	for (int i = 0; i < N; i++) { cin >> map[i]; }
}

void dfs(int y, int x)
{
	static int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
	static int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };

	for (int d = 0; d < 8; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (map[ny][nx] == '0') continue;

		map[ny][nx] = '0';
		dfs(ny, nx);
	}
}

void solve()
{
	int ans = 0;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x] == '1') {
				dfs(y, x);
				ans++;
			}
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