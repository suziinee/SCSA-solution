#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int N, M;
list<int> rel[10 + 1];
int chk[10 + 1];
int pick[10 + 1];
int money[10 + 1];
int ans[10 + 1];


void input()
{
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		rel[a].push_back(b);
	}
	for (int i = 1; i <= N; i++) {
		cin >> money[i];
	}
}

bool pick_ok() //pick[2]부터 pick[N]까지 조건을 만족하는지 판단
{
	for (int i = 2; i <= N; i++) {
		for (int r : rel[i]) {
			if (pick[i] <= pick[r]) return false;
		}
	}
	return true;
}

void dfs(int n)
{
	if (n > N) {
		if (pick_ok()) { copy(pick, pick + 10 + 1, ans); }
		return;
	}

	for (int i = 2; i <= N; i++) {
		if (chk[i] == 0) {
			pick[n] = money[i];
			chk[i] = 1;
			dfs(n + 1);
			chk[i] = 0;
		}
	}
}

bool compare(const int& i1, const int& i2) { return i1 > i2; }

void solve()
{
	sort(money + 1, money + N + 1, compare);
	pick[1] = money[1];

	dfs(2);
	for (int i = 1; i <= N; i++) { cout << ans[i] << " "; }
}


int main(void)
{
	input();
	solve();
	return 0;
}