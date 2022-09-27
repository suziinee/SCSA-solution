#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAXN 100
int T, N, M;
int cnt;

struct AXIS { int y; int x; };
vector<AXIS> map[MAXN + 1][MAXN + 1];
bool light[MAXN + 1][MAXN + 1];
int chk[MAXN + 1][MAXN + 1]; //현재 방문한 곳에서 최대로 켤 수 있는 불

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { -1, 0, 1, 0 };
queue<AXIS> q;


void bfs()
{
	q.push({ 1, 1 });
	light[1][1] = true; cnt++;
	for (AXIS next : map[1][1]) {
		if (light[next.y][next.x] == false) {
			light[next.y][next.x] = true; cnt++;
		}
	}
	chk[1][1] = cnt;

	while (!q.empty()) {
		AXIS cur = q.front(); q.pop();

		//현재 불을 켤 수 있는 곳은 모두 켜기
		for (AXIS next : map[cur.y][cur.x]) {
			if (light[next.y][next.x] == false) {
				light[next.y][next.x] = true; cnt++;
			}
		}

		//인접한 곳 확인
		for (int d = 0; d < 4; d++) {
			int nx = cur.x + dx[d];
			int ny = cur.y + dy[d];
			if (nx<1 || ny<1 || nx>N || ny>N) continue;
			if (light[ny][nx] == false) continue; //불이 꺼진 곳으로는 이동 못함
			if (chk[ny][nx] < cnt) {
				chk[ny][nx] = cnt;
				q.push({ ny, nx });
			}
		}
	}
}

void input()
{
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> M;

		//초기화
		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= N; x++) {
				map[y][x].clear();
				light[y][x] = false;
				chk[y][x] = 0;
			}
		}
		cnt = 0; 
		q = {};

		int u, v, p, q;
		for (int i = 0; i < M; i++) {
			cin >> u >> v >> p >> q;
			map[u][v].push_back({ p, q });
		}

		bfs();
		cout << cnt << "\n";
	}
}


int main()
{
	input();
	return 0;
}