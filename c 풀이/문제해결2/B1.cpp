#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
class DAY {
	public :
		int m; int d;

		bool operator>(const DAY& d1) {
			if (m == d1.m) return d > d1.d;
			return m > d1.m;
		}
		bool operator<(const DAY& d1) {
			if (m == d1.m) return d < d1.d;
			return m < d1.m;
		}
		bool operator<=(const DAY& d1) {
			if (m == d1.m) return d <= d1.d;
			return m <= d1.m;
		}
		bool operator>=(const DAY& d1) {
			if (m == d1.m) return d >= d1.d;
			return m >= d1.m;
		}
		bool operator==(const DAY& d1) {
			if (m == d1.m) return d == d1.d;
			return m == d1.m;
		}
};
struct FLO { DAY st; DAY en; };
vector<FLO> flo;


void input()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int sm, sd, em, ed;
		cin >> sm >> sd >> em >> ed;
		flo.push_back({ {sm, sd}, {em, ed} });
	}
}

bool compare(const FLO& f1, const FLO& f2)
{
	if (f1.st.m == f2.st.m) {
		return f1.st.d < f2.st.d;
	}
	return f1.st.m < f2.st.m;
}

int solve()
{
	int ans = 0;
	sort(flo.begin(), flo.end(), compare);

	DAY e = { 3, 1 }; int i = 0;
	DAY last_day = { 11,30 };

	while (true) {
		DAY max = { 0,0 };
		while (i < n && flo[i].st <= e) {
			if (max < flo[i].en) max = flo[i].en;
			i++;
		}

		if (max <= e) return 0;
		ans++;
		if (max > last_day) return ans;
		e = max;
	}
}

void output(const int& ans)
{
	cout << ans;
}


int main()
{
	input();
	int ans = solve();
	output(ans);
	return 0;
}