#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 50
int N, M, K;
vector<int> conn[MAXN + 1];
bool chk[MAXN + 1]; //dfs 방문 확인용


void input()
{
	cin >> N >> M >> K;
	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		conn[u].push_back(v);
		conn[v].push_back(u);
	}
}

void dfs(int n, int& cnt)
{
	chk[n] = true;
	cnt++;
	for (int nn : conn[n]) {
		if (chk[nn]) continue;
		dfs(nn, cnt);
	}
}

void solve()
{
	vector<int> cand;

	for (int i = 1; i <= N; i++) {
		if (chk[i] == false) {
			int cnt = 0;
			dfs(i, cnt);
			cand.push_back(cnt);
		}
	}

	sort(cand.begin(), cand.end(), greater<int>()); //내림차순 정렬
	
	int ans = 0; int end;
	if (K + 1 > (int)cand.size()) end = (int)cand.size();
	else end = K + 1;

	for (int i = 0; i < end; i++) ans += cand[i];
	cout << ans;
}


int main()
{
	input();
	solve();
	return 0;
}