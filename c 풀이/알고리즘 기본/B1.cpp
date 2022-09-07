#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T, N, K;
vector<int> nums;
int pick[20]; //nums의 i번째 인덱스가 뽑혔으면 1, 안뽑혔으면 0
int flag;
int chk[2] = { 0, 1 };


void dfs(int n)
{
	if (n == N) {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			if (pick[i] == 1) sum += nums[i];
		}
		if (sum == K && flag == 0) {
			cout << "YES" << "\n";
			flag = 1;
		}
		return;
	}

	for (int i = 0; i < 2; i++) {
		pick[n] = chk[i];
		dfs(n + 1);
	}
}

void solve()
{
	dfs(0);
	if (flag == 0) cout << "NO" << "\n";
}

void input()
{
	cin >> T;
	for (int t = 0; t < T; t++) {
		//초기화
		nums = {};
		fill(pick, pick + 20, 0);
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