#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAXN 30
int N, A, B;
int map[MAXN][MAXN];
int chk[MAXN][MAXN];

struct AXIS { 
	int y, x, dist;
	bool operator<(const AXIS& a) const { return dist > a.dist; }
};
priority_queue<AXIS> pq;


void input()
{
	cin >> N >> A >> B;
	char ch;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> ch;
			if (ch == '(') map[y][x] = 1;
			else map[y][x] = 2;
		}
	}
}

int bfs(int y, int x)
{
	static int dx[] = { 0, 1, 0, -1 };
	static int dy[] = { -1, 0, 1, 0 };

	pq = {};
	fill(&chk[0][0], &chk[MAXN - 1][MAXN], 0x7fffffff);

	pq.push({ y, x, 0 });
	chk[y][x] = 0;
	while (!pq.empty()) {
		AXIS cur = pq.top(); pq.pop();
		for (int d = 0; d < 4; d++) {
			int nx = cur.x + dx[d];
			int ny = cur.y + dy[d];
			int ndist;
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (map[cur.y][cur.x] == map[ny][nx]) {
				ndist = cur.dist + A;
			}
			else {
				ndist = cur.dist + B;
			}
			if (chk[ny][nx] <= ndist) continue;
			chk[ny][nx] = ndist;
			pq.push({ ny, nx, ndist });
		}
	}
	
	int max = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (max < chk[y][x]) max = chk[y][x];
		}
	}
	return max;
}

void solve()
{
	int ans = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			int ret = bfs(y, x);
			if (ans < ret) ans = ret;
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