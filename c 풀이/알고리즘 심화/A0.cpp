#include <iostream>
using namespace std;

#define MAXN 13
int N;
int flag_col[MAXN];
int flag_r[2 * MAXN - 1]; //flag_l[r-c+(N-1)]
int flag_l[2 * MAXN - 1]; //flag_l[r+c]
int ans;


void input()
{
	cin >> N;
}

void dfs(int r) //모두 다른 열에 놓아질것, r행이 놓아질 열 선택
{
	if (r >= N) {
		ans++;
		return;
	}

	for (int c = 0; c < N; c++) {
		if (flag_col[c]) continue;
		if (flag_r[r - c + (N - 1)]) continue;
		if (flag_l[r + c]) continue;

		flag_col[c] = 1;
		flag_r[r - c + (N - 1)] = 1;
		flag_l[r + c] = 1;
		dfs(r + 1);
		flag_col[c] = 0;
		flag_r[r - c + (N - 1)] = 0;
		flag_l[r + c] = 0;
	}
}

void solve()
{
	dfs(0);
	cout << ans;
}


int main(void)
{
	input();
	solve();
	return 0;
}