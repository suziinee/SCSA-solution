#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;

struct GRASS {
	long long int s;
	long long int e;
	bool operator<(const GRASS& g) { return s < g.s; }
};
vector<GRASS> grass;


void input()
{
	cin >> N >> M;
	long long int s, e;
	for (int i = 0; i < M; i++) {
		cin >> s >> e;
		grass.push_back({ s, e });
	}
}

bool check(const long long int& d)
{
	long long int cow_pos = grass[0].s;
	int g_idx = 0;
	for (int i = 0; i < N - 1; i++) {
		cow_pos += d;
		while (g_idx < M && grass[g_idx].e < cow_pos) g_idx++;
		if (g_idx == M) return false;
		if (cow_pos < grass[g_idx].s) cow_pos = grass[g_idx].s;
	}
	return true;
}

int bst(long long int st, long long int en)
{
	long long int ans; long long int mid;
	while (st <= en) {
		mid = (st + en) / 2;
		if (check(mid)) { //더 큰 D를 찾을 수 있음
			ans = mid;
			st = mid + 1;
		}
		else en = mid - 1;
	}
	return ans;
}

void solve()
{
	sort(grass.begin(), grass.end());
	cout << bst(0, (grass[M - 1].e - grass[0].s) / (N - 1));
}


int main()
{
	input();
	solve();
	return 0;
}