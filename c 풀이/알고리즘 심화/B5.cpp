#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 25
int N;
int le[MAXN + 1];
int ri[MAXN + 1];
int ans = 0;

int prefix_r[MAXN + 1];


void input()
{
	cin >> N;
	for (int i = 1; i <= N; i++) { cin >> le[i]; }
	for (int i = 1; i <= N; i++) {
		cin >> ri[i];
		if (i == 1) prefix_r[i] = ri[i];
		else prefix_r[i] = prefix_r[i - 1] + ri[i];
	}
}

void dfs(int l, int r, int score)
{
	if (score + prefix_r[N] - prefix_r[r - 1] <= ans) return;

	if (l > N || r > N) {
		if (ans < score) ans = score;
		return;
	}

	//오른쪽이 더 작으면 오른쪽 버리기
	if (le[l] > ri[r]) dfs(l, r + 1, score + ri[r]);
	else {
		//왼쪽만 버리기 
		dfs(l + 1, r, score);
		//왼쪽 + 오른쪽 버리기 
		dfs(l + 1, r + 1, score);
	}
}

void solve()
{
	dfs(0, 0, 0);
	cout << ans;
}


int main(void)
{
	input();
	solve();
	return 0;
}