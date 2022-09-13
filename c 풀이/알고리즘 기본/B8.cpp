#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T, N, B;
int cows[20 + 1];
int ans = 0x7fffffff;


void dfs(int n, int sum)
{
	if (sum > ans) return;
	if (n > N) {
		if (sum >= B && ans > sum) ans = sum;
		return;
	}

	//n번째 소 포함
	dfs(n + 1, sum + cows[n]);
	//n번째 소 미포함
	dfs(n + 1, sum);
}

void solve()
{
	dfs(1, 0);
	cout << ans - B << "\n";
}


void input()
{
	cin >> T;
	for (int t = 0; t < T; t++) {
		//초기화
		fill(cows, cows + 20 + 1, 0);
		ans = 0x7fffffff;

		cin >> N >> B;
		for (int i = 1; i <= N; i++) {
			cin >> cows[i];
		}

		solve();
	}
}


int main(void)
{
	input();
	return 0;
}