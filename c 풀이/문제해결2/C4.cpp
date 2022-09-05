#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, t;
struct P { long long int st; long long int sp; };
vector<P> stu;


void input()
{
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		int st, sp;
		cin >> st >> sp;
		stu.push_back({ st, sp });
	}
}

void output(const int& ans)
{
	cout << ans;
}

int solve()
{
	int ans = 0;
	
	for (int i = 0; i < n; i++) {
		stu[i].st = stu[i].st + t * stu[i].sp;
	}

	long long int tmp = stu[n - 1].st; ans++;
	for (int i = n - 2; i >= 0; i--) {
		if (stu[i].st >= tmp) {
			continue;
		}
		else {
			tmp = stu[i].st;
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