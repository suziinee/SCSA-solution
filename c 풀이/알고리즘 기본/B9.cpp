#include <iostream>
#include <string>
#include <queue>
using namespace std;

#define MAXN 1000
int N, K;
int st, en;
string code[MAXN + 1];

queue<int> q;
int chk[MAXN + 1];
int path[MAXN + 1];


void input()
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> code[i];
	}
	cin >> st >> en;
}

int is_haming(const string& s1, const string& s2)
{
	int cnt = 0;
	for (int i = 0; i < K; i++) {
		if (s1[i] != s2[i]) cnt++;
	}
	if (cnt == 1) return 1;
	return 0;
}

int bfs()
{
	q.push(st);
	chk[st] = 1;
	path[st] = -1;
	
	while (!q.empty()) {
		int n = q.front(); q.pop();

		for (int i = 1; i <= N; i++) {
			if (chk[i]) continue;
			if (!is_haming(code[n], code[i])) continue;

			path[i] = n;
			chk[i] = 1;
			q.push(i);
			if (i == en) return 1;
		}
	}

	return -1;
}

void print_route(int num)
{
	if (num == -1) return;
	print_route(path[num]);
	cout << num << " ";
}

void solve()
{
	int b = bfs();

	if (b == -1) cout << -1 << "\n";
	else print_route(en);
}


int main(void)
{
	input();
	solve();
	return 0;
}