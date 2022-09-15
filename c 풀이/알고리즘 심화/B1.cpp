#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAXN 100
int N, M;
int conn[MAXN + 1][MAXN + 1];
int chk[MAXN + 1];
int path[MAXN + 1];
vector<int> route;

struct STATUS { int cur; int sum; };
struct COMP {
	bool operator()(STATUS& s1, STATUS& s2) { return s1.sum > s2.sum; }
};
priority_queue<STATUS, vector<STATUS>, COMP> pq;


void input()
{
	cin >> N >> M;

	int s, n, val;
	for (int i = 0; i < M; i++) {
		cin >> s >> n >> val;
		conn[s][n] = val;
		conn[n][s] = val;
	}
}

void search_route(int n)
{
	if (n == -1) return;
	search_route(path[n]);
	route.push_back(n);
}

int bfs()
{
	fill(chk, chk + MAXN + 1, 0x7fffffff);
	pq = {};

	pq.push({ 1, 0 });
	chk[1] = 0;
	path[1] = -1;

	while (!pq.empty()) {
		STATUS data = pq.top(); pq.pop();
		if (data.cur == N) return data.sum;

		for (int i = 1; i <= N; i++) {
			if (conn[data.cur][i] == 0) continue;
			if (chk[i] <= data.sum + conn[data.cur][i]) continue;
			chk[i] = data.sum + conn[data.cur][i];
			path[i] = data.cur;
			pq.push({ i, data.sum + conn[data.cur][i] });
		}
	}
}

void solve()
{
	int init_route = bfs();
	search_route(N);

	int max_route = -1; int tmp; int candi;

	//농부가 왔던 경로 하나씩 변경해보기
	for (int i = 0; i < route.size() - 1; i++) {
		tmp = conn[route[i]][route[i + 1]];
		conn[route[i]][route[i + 1]] = 2 * tmp;
		conn[route[i + 1]][route[i]] = 2 * tmp;

		candi = bfs();
		if (candi > max_route) max_route = candi;

		conn[route[i]][route[i + 1]] = tmp;
		conn[route[i + 1]][route[i]] = tmp;
	}

	cout << max_route - init_route;
}


int main(void)
{
	input();
	solve();
	return 0;
}