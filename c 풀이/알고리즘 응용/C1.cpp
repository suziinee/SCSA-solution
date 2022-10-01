#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAXN 1000
#define MAXL 1000

vector<int> obama[MAXL * MAXN + 1]; //각 시간마다 제약이 걸린 점들 저장
vector<int> o_loc; //오바마가 방문하는 점들

int N, M, A, B, K, G;
int adj[MAXN + 1][MAXN + 1];

struct STATUS {
	int n; //현재 은탁 위치
	int sum_time; //현재까지의 시간
	bool operator<(const STATUS& s) const { return sum_time > s.sum_time; }
};
priority_queue<STATUS> pq;
int chk[MAXN + 1]; //현재 도로에서의 최소 시간


void input()
{
	cin >> N >> M >> A >> B >> K >> G;
	int g;
	for (int i = 0; i < G; i++) {
		cin >> g;
		o_loc.push_back(g);
	}
	int u, v, t;
	for (int i = 0; i < M; i++) {
		cin >> u >> v >> t;
		adj[u][v] = t;
		adj[v][u] = t;
	}
}

void obama_init() //0분부터 마지막 시간까지 오바마가 있는 점들 저장
{
	int time = 0;
	for (int i = 0; i < G - 1; i++) {
		int interval = adj[o_loc[i]][o_loc[i + 1]];
		for (int t = time; t < time + interval; t++) {
			obama[t].push_back(o_loc[i]);
			obama[t].push_back(o_loc[i + 1]);
		}
		time += interval;
	}
}

int bfs()
{
	fill(chk, chk + MAXN + 1, 0x7fffffff);
	pq.push({ A, K });
	chk[A] = K;

	while (!pq.empty()) {
		STATUS cur = pq.top(); pq.pop();
		if (cur.n == B) return cur.sum_time - K;

		//현재 교차로에 통제되어 있는 도로가 존재
		int cst = -1;
		if (!obama[cur.sum_time].empty()) {
			if (obama[cur.sum_time][0] == cur.n) { //[1]로 가면 안됨
				cst = obama[cur.sum_time][1];
				pq.push({ cur.n, cur.sum_time + 1 });
			}
			else if (obama[cur.sum_time][1] == cur.n) { //[0]으로 가면 안됨
				cst = obama[cur.sum_time][0];
				pq.push({ cur.n, cur.sum_time + 1 });
			}
		}
		
		for (int i = 1; i <= N; i++) {
			if (adj[cur.n][i] == 0) continue;
			if (i == cst) continue;
			if (chk[i] <= cur.sum_time + adj[cur.n][i]) continue;
			chk[i] = cur.sum_time + adj[cur.n][i];
			pq.push({ i, chk[i] });
		}
	}
}

void solve()
{
	obama_init();
	cout << bfs();
}


int main()
{
	input();
	solve();
	return 0;
}