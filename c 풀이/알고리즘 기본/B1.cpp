#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T, N, K;
vector<int> nums;


bool dfs(int s, int sum) //dfs를 행하던 중 만족하지 않으면 false를 리턴
{
	if (sum == K) return true;
	if (sum > K) return false;
	if (n == N) return false;

	for (int i = s; s <= N; i++) {
		if (dfs(i + 1, sum + nums[i])) return true;
	}
	return false; //다 돌아도 true가 없었다면 false 리턴
}

void solve()
{
	if (dfs(0, 0)) cout << "YES" << "\n";
	else cout << "NO" << "\n";
}

void input()
{
	cin >> T;
	for (int t = 0; t < T; t++) {
		//초기화
		nums = {};

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