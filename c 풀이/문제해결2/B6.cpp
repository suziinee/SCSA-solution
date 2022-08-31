#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int T;
int n, m;
struct PAPER {
	int idx; int pri;
};
deque<PAPER> q;
vector<PAPER> ans;


void output()
{
	cout << ans.size() << "\n";
}


bool is_priority(const int& t)
{
	for (int i = 0; i < q.size(); i++) {
		if (q[i].pri > t) return false;
	}
	return true;
}


void solve()
{
	while (!q.empty()) {
		PAPER tmp = q.front(); q.pop_front();
		if (is_priority(tmp.pri)) { //tmp가 가장 우선순위라면
			ans.push_back(tmp);
			if (tmp.idx == m) return;
		}
		else {
			q.push_back(tmp);
		}
	}
}


void input()
{
	cin >> T;
	for (int t = 0; t < T; t++) {
		//초기화
		q = {};
		ans = {};

		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			PAPER p;
			cin >> p.pri;
			p.idx = i;
			q.push_back(p);
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