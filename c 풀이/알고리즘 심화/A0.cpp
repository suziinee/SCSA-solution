#include <iostream>
using namespace std;

#define MAXN 13
int N;
int chess[MAXN + 1][MAXN + 1];
int flag[MAXN + 1];
int ans;


void input()
{
	cin >> N;
}

int check(const int& r, const int& c)
{
	//좌측 상향 대각선 확인
	for (int rr = r - 1, cc = c + 1; rr >= 1 && cc <= N; rr--, cc++) {
		if (chess[rr][cc]) return 0;
	}
	//우측 상향 대각선 확인
	for (int rr = r - 1, cc = c - 1; rr >= 1 && cc >= 1; rr--, cc--) {
		if (chess[rr][cc]) return 0;
	}
	return 1;
}

void dfs(int r) //모두 다른 열에 놓아질것, r행이 놓아질 열 선택
{
	if (r > N) {
		ans++;
		return;
	}

	for (int c = 1; c <= N; c++) {
		if (flag[c]) continue;
		if (!check(r, c)) continue; //좌측 상향, 우측 상향 대각선 선택

		flag[c] = 1;
		chess[r][c] = 1;
		dfs(r + 1);
		flag[c] = 0;
		chess[r][c] = 0;
	}
}

void solve()
{
	dfs(1);
	cout << ans;
}


int main(void)
{
	input();
	solve();
	return 0;
}