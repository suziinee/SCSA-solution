#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T, n, k;
vector<int> nums;
int pick[20];
int flag;


void dfs(int depth, int s)
{
	if (depth == n) return;

	if (1 <= depth && depth < n) { //1개부터 n개까지
		int sum = 0;
		for (int i = 0; i < depth; i++) {
			sum += pick[i];
		}
		if (sum == k && flag == 0) {
			cout << "YES" << "\n";
			flag = 1;
			return;
		}
	}

	for (int i = s; i < n; i++) {
		pick[depth] = nums[i];
		dfs(depth + 1, i + 1);
	}
}

void solve()
{
	dfs(0, 0);
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

		cin >> n >> k;
		for (int i = 0; i < n; i++) {
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