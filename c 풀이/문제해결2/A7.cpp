#include <iostream>
#include <algorithm>
#include <deque>
#include <stack>
using namespace std;

int n;
struct MOVIE {
	int start; int end;
};
deque<MOVIE> movie;
int ans;

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		MOVIE tmp;
		cin >> tmp.start >> tmp.end;
		movie.push_back(tmp);
	}
}

void output()
{
	cout << ans;
}

bool compare(const MOVIE& m1, const MOVIE& m2)
{
	if (m1.end == m2.end) {
		return m1.start > m2.start;
	}
	else {
		return m1.start > m2.start;
	}
}

void solve()
{
	sort(movie.begin(), movie.end(), compare);

	stack<MOVIE> s;
	MOVIE tmp = movie.front(); movie.pop_front();
	s.push(tmp);
	ans++;

	for (int i = 0; i < movie.size(); i++) {
		if (movie[i].end < s.top().start) {
			s.push(movie[i]);
			ans++;
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	input();
	solve();
	output();
	return 0;
}
