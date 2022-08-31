#include <iostream>
#include <algorithm>
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
int p[100];


void output()
{
	cout << ans.size() << "\n";
}


bool compare(const int& p1, const int& p2)
{
	return p1 > p2;
}


void solve()
{
	sort(p, p + n, compare);

	for (int i = 0; i < n; i++) {
		while (true) {
			PAPER tmp = que.front(); que.pop();
			if (tmp.pri == p[i]) {
				ans.push_back(tmp);
				if (tmp.idx == m) return;
				break;
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
			p[i] = paper.pri;
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