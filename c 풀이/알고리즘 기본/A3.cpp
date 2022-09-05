#include <iostream>
#include <queue>
using namespace std;

int st; int en;
struct NUM { int n; int ans; };
int prime[10000];


void init()
{
	for (int i = 1; i <= 9999; i++) {
		prime[i] = i;
	}

	for (int i = 2; i*i < 10000; i++) {
		if (prime[i]) {
			int j = 2;
			while ((i*j) < 10000) {
				prime[i*j] = 0;
				j++;
			}
		}
	}
}

void input()
{
	cin >> st >> en;

	init();
}

const int d[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int bfs()
{
	queue<NUM> q;
	int chk[10000] = { 0 }; //방문 여부
	q.push({ st, 0 });
	chk[st] = 1;

	while (!q.empty()) {
		NUM tmp = q.front(); q.pop();
		NUM next;
		next.ans = tmp.ans + 1;

		//1의 자리
		for (int i = 0; i < 10; i++) {
			if (i == 1 || i == 3 || i == 7 || i == 9) {
				next.n = (tmp.n / 10) * 10 + i;
				if (next.n == en) return next.ans; //종료조건
				if (prime[next.n] != 0 && chk[next.n] == 0) {
					q.push(next);
					chk[next.n] = 1;
				}
			}
		}
		//10의 자리
		for (int i = 0; i < 10; i++) {
			next.n = (tmp.n / 100) * 100 + d[i] * 10 + (tmp.n % 10);
			if (next.n == en) return next.ans; //종료조건
			if (prime[next.n] != 0 && chk[next.n] == 0) {
				q.push(next);
				chk[next.n] = 1;
			}
		}
		//100의 자리
		for (int i = 0; i < 10; i++) {
			next.n = (tmp.n / 1000) * 1000 + d[i] * 100 + (tmp.n % 100);
			if (next.n == en) return next.ans; //종료조건
			if (prime[next.n] != 0 && chk[next.n] == 0) {
				q.push(next);
				chk[next.n] = 1;
			}
		}
		//1000의 자리
		for (int i = 0; i < 10; i++) {
			if (i != 0) {
				next.n = d[i] * 1000 + (tmp.n % 1000);
				if (next.n == en) return next.ans; //종료조건
				if (prime[next.n] != 0 && chk[next.n] == 0) {
					q.push(next);
					chk[next.n] = 1;
				}
			}
		}
	}

	return -1;
}

int solve()
{
	int ans = bfs();
	return ans;
}

void output(const int& ans)
{
	cout << ans;
}


int main()
{
	input();
	int ans = solve();
	output(ans);
	return 0;
}