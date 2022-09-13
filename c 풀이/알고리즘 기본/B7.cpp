#include <iostream>
#include <algorithm>
#include <queue>
#include <list>
#include <vector>
using namespace std;

#define MAXN 10
struct CONN { int n; int val; };
struct STATUS { int n; int sum; };
int N;
list<CONN> conn[MAXN + 1];


void input()
{
	cin >> N;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			int val;
			cin >> val;
			if (val) {
				conn[y].push_back({ x, val });
			}
		}
	}
}

int bfs()
{
	queue<int> q;
	int chk[MAXN + 1]; //1에서 갈 수 있는 최단경로
	fill(chk, chk + MAXN + 1, 0x7fffffff);

	q.push(1);
	chk[1] = 0;
	if (N == 1) return chk[1];

	while (!q.empty()) {
		int data = q.front(); q.pop();

		for (CONN c : conn[data]) {
			if (chk[c.n] > chk[data] + c.val) {
				q.push(c.n);
				chk[c.n] = chk[data] + c.val;
			}
		}
	}

	return chk[N];
}


int solve()
{
	int ans = bfs();

	if (ans == 0x7fffffff) return 0;
	else return ans;
}


int main(void)
{
	input();
	int ans = solve();
	cout << ans;
	return 0;
}