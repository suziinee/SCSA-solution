#include <iostream>
#include <queue>
using namespace std;

#define MAXN 10
int N;
int ans;
int total_tree;
int map[MAXN][MAXN];

struct AXIS { int y; int x; };
vector<AXIS> tree;
vector<AXIS> fire;
queue<AXIS> q;
bool chk[MAXN][MAXN];


void input()
{
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			if (map[y][x] == 1) {
				tree.push_back({ y, x });
				total_tree++;
			}
			else if (map[y][x] == 2) {
				fire.push_back({ y, x });
			}
		}
	}
}

int flood_fill()
{
	static int dx[] = { 0, 1, 0, -1 };
	static int dy[] = { -1, 0, 1, 0 };

	q = {};
	fill(&chk[0][0], &chk[MAXN - 1][MAXN], false);

	for (AXIS f : fire) {
		q.push({ f.y, f.x });
		chk[f.y][f.x] = true;
	}
	
	int cnt = 0;
	while (!q.empty()) {
		AXIS cur = q.front(); q.pop();
		for (int d = 0; d < 4; d++) {
			int nx = cur.x + dx[d];
			int ny = cur.y + dy[d];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (map[ny][nx] != 1 || chk[ny][nx]) continue;
			chk[ny][nx] = true;
			q.push({ ny, nx });
			cnt++;
		}
	}

	return total_tree - cnt;
}

void dfs(int s, int cut)
{
	if (cut > 2) return;
	if (cut >= 0 && cut <= 2) {
		int ret = flood_fill();
		ret -= cut;
		if (ans < ret) ans = ret;
	}
	if (s == tree.size()) return;

	for (int i = s; i < tree.size(); i++) {
		map[tree[i].y][tree[i].x] = 0;
		dfs(i + 1, cut + 1);
		map[tree[i].y][tree[i].x] = 1;
	}
}

void solve()
{
	dfs(0, 0);
	cout << ans;
}


int main()
{
	input();
	solve();
	return 0;
}