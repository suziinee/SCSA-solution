#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 100
int N;
int map[MAXN + 1][MAXN + 1];

struct AXIS { int x; int y; int sum; };
struct COMP {
	bool operator()(AXIS& a1, AXIS& a2) { return a1.sum > a2.sum; }
};
priority_queue<AXIS, vector<AXIS>, COMP> pq;
int chk[MAXN + 1][MAXN + 1];


void input()
{
	cin >> N;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			scanf("%1d", &map[y][x]);
		}
	}
}

int bfs()
{
	static int dx[] = { 0, 1, 0, -1 };
	static int dy[] = { -1, 0, 1, 0 };
	fill(&chk[0][0], &chk[MAXN][MAXN + 1], 0x7fffffff); //최소의 합

	pq.push({ 1, 1, map[1][1] });
	chk[1][1] = map[1][1];

	while (!pq.empty()) {
		AXIS data = pq.top(); pq.pop();
		if (data.x == N && data.y == N) return data.sum; //pq로 바뀌고 종료조건을 여기에 설정

		for (int dir = 0; dir < 4; dir++) {
			AXIS ndata;
			ndata.x = data.x + dx[dir];
			ndata.y = data.y + dy[dir];
			ndata.sum = data.sum + map[ndata.y][ndata.x];

			if (ndata.x<1 || ndata.y<1 || ndata.x>N || ndata.y>N) continue;
			if (ndata.sum >= chk[ndata.y][ndata.x]) continue;

			pq.push(ndata);
			chk[ndata.y][ndata.x] = ndata.sum;
		}
	}
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