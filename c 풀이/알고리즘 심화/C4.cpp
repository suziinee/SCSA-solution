#include <iostream>
#include <queue>
using namespace std;

#define MAXN 10000
#define MAXX 200
int N, M, X;
int temp[MAXN + 1];
int chk[MAXN + 1][3][MAXX + 1]; //현재 방, 이전 방의 온도, last_x / 가중치가 다르므로 방문배열 아님

struct ROOM { int n; int time; };
vector<ROOM> conn[MAXN + 1];

struct STATUS {
	int cur;
	int sum_time;
	int x;
	int last_x;
	bool operator<(const STATUS& s) const { return sum_time > s.sum_time; }
};
priority_queue<STATUS> pq;


void input()
{
	cin >> N >> M >> X;
	for (int i = 1; i <= N; i++) {
		cin >> temp[i];
	}
	int u, v, time;
	for (int i = 0; i < M; i++) {
		cin >> u >> v >> time;
		conn[u].push_back({ v, time });
		conn[v].push_back({ u, time });
	}
}


int bfs()
{
	pq.push({ 1, 0, temp[1], X }); //현재위치, 시간총합, 현재 방의 온도, last_x
	chk[1][temp[1]][X] = 0; //현재 방, x, last_x

	while (!pq.empty()) {
		STATUS data = pq.top(); pq.pop();
		if (data.cur == N) return data.sum_time;

		for (ROOM r : conn[data.cur]) {
			STATUS ndata;
			ndata.cur = r.n;
			ndata.sum_time = data.sum_time + r.time;

			if (data.last_x - r.time > 0) { //제약이 있음
				if (data.x == 0 && temp[r.n] == 2) continue; //0->2
				if (data.x == 2 && temp[r.n] == 0) continue; //2->0

				if (temp[r.n] == 1) { //0->1, 2->1, (1->1) 
					ndata.x = data.x; //****
					ndata.last_x = data.last_x - r.time;
				}
				else { //(1->2), (1->0), 0->0, 2->2 / 새로 제약이 발생
					ndata.x = temp[r.n];
					ndata.last_x = X;
				}
			}
			else { //제약이 없어지거나 없음
				if (temp[r.n] == 1) {  //0->1, 2->1, 1->1
					ndata.x = temp[r.n];
					ndata.last_x = 0;
				}
				else { //0->2, 2->0, 1->2, 1->0, 0->0, 2->2
					ndata.x = temp[r.n];
					ndata.last_x = X;
				}
			}

			if (chk[ndata.cur][ndata.x][ndata.last_x] <= ndata.sum_time) continue;
			chk[ndata.cur][ndata.x][ndata.last_x] = ndata.sum_time;
			pq.push(ndata);
		}
	}
}


void solve()
{
	//int chk[MAXN + 1][3][MAXX + 1] 초기화
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k <= X; k++) {
				chk[i][j][k] = 0x7fffffff;
			}
		}
	}
	cout << bfs();
}


int main()
{
	input();
	solve();
	return 0;
}

