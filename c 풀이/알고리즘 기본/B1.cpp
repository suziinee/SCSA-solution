#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T, N, K;
vector<int> nums;


bool dfs(int n, int sum) //dfs를 행하던 중 만족하지 않으면 false를 리턴
{
	if (sum == K) return true;
	if (sum > K) return false;
	if (n == N) return false;

	//n번째 포함
	if (dfs(n + 1, sum + nums[n])) return true;
	//n번째 미포함
	if (dfs(n + 1, sum)) return true;
	//둘 다 true가 아닐 경우
	return false;
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