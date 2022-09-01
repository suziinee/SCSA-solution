#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n, l;
vector<int> gun;
struct AXIS { int x; int y; };
vector<AXIS> animal;
int ans;


void input()
{
	cin >> m >> n >> l;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		gun.push_back(a);
	}
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (y > l) continue;
		animal.push_back({ x, y });
	}
}


void output()
{
	cout << ans;
}


int lower_bound(int s, int e, const int& tar) //tar보다 크거나 같은 사대의 최소 인덱스
{
	int ret = -1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (tar <= gun[mid]) {
			ret = mid;
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	return ret;
}


void solve()
{
	sort(gun.begin(), gun.end());

	for (auto a : animal) { //모든 동물에 대해 자신을 맞출 수 있는 사대 탐색
		int low = a.x - (l - a.y);
		int up = a.x + (l - a.y);

		int idx = lower_bound(0, gun.size()-1, low);
		if (idx == -1 || up < gun[idx]) continue;
		ans++;
	}
}


int main()
{
	input();
	solve();
	output();
	return 0;
}