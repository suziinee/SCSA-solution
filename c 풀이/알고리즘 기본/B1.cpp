#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T, N, K;
vector<int> nums;
bool flag;


void dfs(int n, int sum)
{
	if (sum == K) { flag = true; return; }
	if (n == N) return;

	//n번째 포함
	dfs(n + 1, sum + nums[n]);
	//n번째 미포함
	dfs(n + 1, sum);
}

void solve()
{
	dfs(0, 0);
	if (flag) cout << "YES" << "\n";
	else cout << "NO" << "\n";
}

void input()
{
	cin >> T;
	for (int t = 0; t < T; t++) {
		//초기화
		nums = {};
		flag = 0;

		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			int a;
			cin >> a;
			nums.push_back(a);
		}

		solve();
	}
}


int main(void)
{
	input();
	return 0;
}