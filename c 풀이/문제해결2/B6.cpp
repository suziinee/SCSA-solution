#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int T;
int n, m;
struct PAPER {
	int idx; int pri;
};
queue<PAPER> que;
vector<PAPER> ans;
int p[10];


void output()
{
	cout << ans.size() << "\n";
}


void solve()
{
	for (int i = 9; i >= 1; i--) {
		while (true) {
			if (p[i] == 0) break;

			PAPER tmp = que.front(); que.pop();
			if (tmp.pri == i) {
				ans.push_back(tmp);
				p[i]--;
				if (tmp.idx == m) return;
			}
			else {
				que.push(tmp);
			}
		}
	}
}


void input()
{
	cin >> T;
	for (int t = 0; t < T; t++) {
		que = {};
		ans = {};
		memset(p, 0, sizeof(p));

		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			PAPER paper;
			cin >> paper.pri;
			paper.idx = i;
			p[paper.pri]++;
			que.push(paper);
		}

		solve();
		output();
	}
}


int main()
{
	input();
	return 0;
}