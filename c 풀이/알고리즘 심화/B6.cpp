#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
using namespace std;

#define MAXN 5000
int N, K;
int chk[MAXN + 1][MAXN + 1]; //[마을][남은 r 횟수]
list<int> conn[MAXN + 1];

struct TAXI { int G; int R; };
vector<TAXI> taxi = { {0,0} }; //0번째 택시

struct STATUS { int cur; int sum; int last_r; }; //현재 마을 번호, 현재까지 쌓인 요금, 갈 수 있는 도로의 개수
struct COMP {
	bool operator()(STATUS& s1, STATUS& s2) { return s1.sum > s2.sum; }
};
priority_queue<STATUS, vector<STATUS>, COMP> pq;


void input()
{
	cin >> N >> K;

	int g, r;
	for (int i = 0; i < N; i++) {
		cin >> g >> r;
		taxi.push_back({ g, r });
	}

	int u, v;
	for (int i = 0; i < K; i++) {
		cin >> u >> v;
		conn[u].push_back(v);
		conn[v].push_back(u);
	}
}

int bfs()
{
	fill(&chk[0][0], &chk[MAXN][MAXN + 1], 0x7fffffff);

	pq.push({ 1, taxi[1].G, taxi[1].R });
	chk[1][taxi[1].R] = taxi[1].G;

	while (!pq.empty()) {
		STATUS data = pq.top(); pq.pop();
		if (data.cur == N) return chk[data.cur][data.last_r]; //우선순위 큐의 종료조건

		if (data.last_r) { //현재 마을에서 갈아타거나 갈아타지 않아도 됨
			//다음 마을로 가기
			for (int nn : conn[data.cur]) {
				STATUS ndata = { nn, chk[data.cur][data.last_r], data.last_r - 1 };
				if (chk[nn][ndata.last_r] <= ndata.sum) continue;
				chk[nn][ndata.last_r] = ndata.sum;
				pq.push(ndata);
			}
		}
		//현재 마을에서 갈아타고 가기
		for (int nn : conn[data.cur]) {
			STATUS ndata = { nn, chk[data.cur][data.last_r] + taxi[data.cur].G, taxi[data.cur].R - 1 };
			if (chk[nn][ndata.last_r] <= ndata.sum) continue;
			chk[nn][ndata.last_r] = ndata.sum;
			pq.push(ndata);
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