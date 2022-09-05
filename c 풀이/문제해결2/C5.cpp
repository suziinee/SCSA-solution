#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
struct MOVIE { int st; int en; };
vector<MOVIE> mov;


void input()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int st, en;
		cin >> st >> en;
		if (en - st < 2) continue;
		mov.push_back({ st, en });
	}
}

void output(const int& ans)
{
	cout << ans;
}

bool compare(const MOVIE& m1, const MOVIE& m2)
{
	if (m1.en == m2.en) {
		return m1.st > m2.st;
	}
	return m1.en < m2.en;
}

int solve()
{
	int ans = 0;
	sort(mov.begin(), mov.end(), compare);

	int s = mov[0].en; ans++;
	for (int i = 1; i < mov.size(); i++) {
		if (mov[i].st >= s) {
			s = mov[i].en;
			ans++;
		}
	}
	
	return ans;
}


int main()
{
	input();
	int ans = solve();
	output(ans);
	return 0;
}