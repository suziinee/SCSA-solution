#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 20
int N;
int tape[MAXN + 5];
int total;
int ans = 0x7fffffff;


void input()
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> tape[i];
		total += tape[i];
	}
}

void dfs(int n, int s, int sum) //depth, start, sum
{
	if (n > (N / 2)) {
		if (abs((total - sum) - sum) < ans) ans = abs((total - sum) - sum);
		return;
	}

	for (int i = s; i <= N; i++) {
		dfs(n + 1, i + 1, sum + tape[i]);
	}
}

void solve()
{
	dfs(1, 1, 0);
	cout << ans;
}


int main(void)
{
	input();
	solve();
	return 0;
}