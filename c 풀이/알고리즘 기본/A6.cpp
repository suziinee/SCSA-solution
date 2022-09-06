#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 100
int n;
int map[MAXN + 1][MAXN + 1];
struct AXIS { int x; int y; int sum; };


void input() 
{
	cin >> n;
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			scanf("%1d", &map[y][x]);
		}
	}
}

int bfs()
{
	queue<AXIS> q;
	int chk[MAXN + 1][MAXN + 1];
	fill(&chk[0][0], &chk[MAXN][MAXN + 1], 0x7fffffff); //최소의 합

	q.push({ 1, 1, map[1][1] });
	chk[1][1] = map[1][1];

	const int dx[] = { 0, 1, 0, -1 };
	const int dy[] = { -1, 0, 1, 0 };
	while (!q.empty()) {
		AXIS data = q.front(); q.pop();

		for (int dir = 0; dir < 4; dir++) {
			AXIS ndata;
			ndata.x = data.x + dx[dir];
			ndata.y = data.y + dy[dir];
			ndata.sum = chk[data.y][data.x] + map[ndata.y][ndata.x];

			if (ndata.x<1 || ndata.y<1 || ndata.x>n || ndata.y>n) continue;
			if (ndata.sum >= chk[ndata.y][ndata.x]) continue;

			q.push(ndata);
			chk[ndata.y][ndata.x] = ndata.sum;
		}
	}

	return chk[n][n];
}

void solve()
{
	int ans = bfs();
	cout << ans;
}


int main(void)
{
	input();
	solve();

	return 0;
}