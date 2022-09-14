#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAXN 25
int N; 
string map[MAXN];
vector<int> ans;

struct AXIS { int y; int x; };
queue<AXIS> q;


void input()
{
	cin >> N;
	for (int i = 0; i < N; i++) { cin >> map[i]; }
}

int bfs(int y, int x)
{
	int cnt = 0;
	static int dx[] = { 0, 1, 0, -1 };
	static int dy[] = { -1, 0, 1, 0 };

	q.push({ y, x });
	map[y][x] = '0';
	cnt++;

	while (!q.empty()) {
		AXIS n = q.front(); q.pop();

		for (int d = 0; d < 4; d++) {
			int nx = n.x + dx[d];
			int ny = n.y + dy[d];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (map[ny][nx] == '0') continue;

			q.push({ ny, nx });
			map[ny][nx] = '0';
			cnt++;
		}
	}

	return cnt;
}

void solve()
{
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x] == '1') {
				int cnt = bfs(y, x);
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