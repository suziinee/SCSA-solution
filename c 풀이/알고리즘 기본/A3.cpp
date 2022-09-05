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

		for (int i = 0; i < 10; i++) {
			int n1 = (tmp.n / 10) * 10 + i;
			int n2 = (tmp.n / 100) * 100 + d[i] * 10 + (tmp.n % 10);
			int n3 = (tmp.n / 1000) * 1000 + d[i] * 100 + (tmp.n % 100);
			int n4 = (i == 0) ? tmp.n : (d[i] * 1000 + (tmp.n % 1000));

			if (n1 == en || n2 == en || n3 == en || n4 == en) return tmp.ans + 1; //종료조건
			
			if (prime[n1] != 0 && chk[n1] == 0) {
				q.push({ n1, tmp.ans + 1 });
				chk[n1] = 1;
			}
			if (prime[n2] != 0 && chk[n2] == 0) {
				q.push({ n2, tmp.ans + 1 });
				chk[n2] = 1;
			}
			if (prime[n3] != 0 && chk[n3] == 0) {
				q.push({ n3, tmp.ans + 1 });
				chk[n3] = 1;
			}
			if (prime[n4] != 0 && chk[n4] == 0) {
				q.push({ n4, tmp.ans + 1 });
				chk[n4] = 1;
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