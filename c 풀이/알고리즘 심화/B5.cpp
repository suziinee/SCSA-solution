#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 25
int N;
int le[MAXN + 1];
int ri[MAXN + 1];
int chk[MAXN + 1][MAXN + 1]; //l, r일때 최대 점수를 담기
int prefix_r[MAXN + 1];
int ans = 0;


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
	//가지치기
	if (chk[l][r] >= score + ri[r]) return;
	if (score + prefix_r[N] - prefix_r[r - 1] <= ans) return;

	//종료조건
	if (l > N || r > N) {
		if (ans < score) ans = score;
		return;
	}

	//오른쪽이 더 작으면 오른쪽 버리기
	if (le[l] > ri[r] && chk[l][r] < score + ri[r]) {
		chk[l][r] = score + ri[r];
		dfs(l, r + 1, score + ri[r]);
	}
	else if (le[l] <= ri[r] && chk[l][r] < score) {
		chk[l][r] = score;
		//왼쪽만 버리기 
		dfs(l + 1, r, score);
		//왼쪽 + 오른쪽 버리기 
		dfs(l + 1, r + 1, score);
	}
}

void solve()
{
	fill(chk[0], chk[MAXN + 1], -1);
	dfs(0, 0, 0);
	cout << ans;
}


int main(void)
{
	input();
	solve();
	return 0;
}