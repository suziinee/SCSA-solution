#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> file;


void input()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		file.push_back(a);
	}
}

void output(const long long int& ans)
{
	cout << ans;
}

int lower_bound(int s, int e, const int& tar)
{
	int ret = -1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (tar <= file[mid]) {
			ret = mid;
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	return ret;
}

long long int solve()
{
	long long int ans = 0;
	sort(file.begin(), file.end());

	int i = 0;
	for (auto f : file) {
		int idx;
		if (f % 10 == 0) {
			idx = lower_bound(0, n - 1, (int)(f*0.9));
		}
		else {
			idx = lower_bound(0, n - 1, (int)(f*0.9) + 1);
		}

		if (idx != -1) {
			ans += i - idx;
		}
		i++;
	}
	
	return ans;
}


int main()
{
	input();
	long long int ans = solve();
	output(ans);
	return 0;
}