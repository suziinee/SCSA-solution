#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> tree;
int ans;


void input()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		tree.push_back(a);
	}
}


void output()
{
	cout << ans;
}


bool possible(const int& tar)
{
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += (tree[i] > tar ? tree[i] - tar : 0);
		if (sum >= m) return true;
	}
	return false;
}


void solve()
{
	int max = -1;
	for (int i = 0; i < n; i++) {
		if (tree[i] > max) max = tree[i];
	}

	int s = 0; int e = max;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (possible(mid)) { //높이를 더 높일 수 있음
			ans = mid;
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
}


int main()
{
	input();
	solve();
	output();
	return 0;
}