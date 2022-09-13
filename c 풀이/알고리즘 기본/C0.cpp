#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
struct CONN { int high; int low; };
vector<CONN> conn;
vector<int> money;
int pick[10];
int chk[10];


void input()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int high, low;
		cin >> high >> low;
		conn.push_back({ high, low });
	}
	for (int i = 0; i < N; i++) {
		int m;
		cin >> m;
		money.push_back(m);
	}
}

bool check()
{
	for (CONN c : conn) {
		if (pick[c.high - 1] <= pick[c.low - 1]) return false;
	}
	return true;
}

bool dfs(int n)
{
	if (n >= N) {
		if (check()) return true;
		return false;
	}

	for (int i = 1; i < N; i++) {
		if (chk[i]) continue;

		pick[n] = money[i];
		chk[i] = 1;
		if (dfs(n + 1)) return true;
		chk[i] = 0;
	}
	return false;
}

bool compare(const int& i1, const int& i2) { return i1 > i2; }

void solve()
{
	sort(money.begin(), money.end(), compare);
	pick[0] = money[0];
	if (dfs(1)) {
		for (int i = 0; i < N; i++) cout << pick[i] << " ";
	}
}


int main(void)
{
	input();
	solve();
	return 0;
}