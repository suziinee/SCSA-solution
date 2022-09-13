#include <iostream>
#include <algorithm>
#include <queue>
#include <list>
using namespace std;

int N;
struct CITY { int n; int val; }; //도시번호, 가중치
list<CITY> city[10 + 1];
queue<int> q;
int chk[10 + 1]; //1부터 해당 도시번호까지 최소 시간


void input()
{
	int n;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> n;
			if (n == 0) continue;
			city[i].push_back({ j, n });
		}
	}
}

int bfs()
{
	fill(chk, chk + 10 + 1, 0x7fffffff);

	q.push(1);
	chk[1] = 0;
	if (N == 1) return 0;

	while (!q.empty()) {
		int data = q.front(); q.pop();

		for (auto a : city[data]) { //a는 list<CITY> 
			if (chk[a.n] > chk[data] + a.val) {
				chk[a.n] = chk[data] + a.val;
				q.push(a.n);
			}
		}
	}

	return chk[N];
}


void solve()
{
	int ans = bfs();
	if (ans == 0x7fffffff) cout << 0;
	else cout << ans;
}


int main(void)
{
	input();
	solve();
	return 0;
}