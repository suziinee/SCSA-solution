#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 25
int N; 
string map[MAXN];
vector<int> ans;


void input()
{
	cin >> N;
	for (int i = 0; i < N; i++) { cin >> map[i]; }
}

int dfs(int y, int x)
{
	int cnt = 1;

	static int dx[] = { 0, 1, 0, -1 };
	static int dy[] = { -1, 0, 1, 0 };

	map[y][x] = '0';

	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (map[ny][nx] == '0') continue;

		cnt += dfs(ny, nx);
	}

	return cnt;
}

void solve()
{
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x] == '1') {
				int cnt = dfs(y, x);
				ans.push_back(cnt);
			}
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << "\n";
	for (int a : ans) { cout << a << "\n"; }
}


int main(void)
{
	input();
	solve();
	return 0;
}