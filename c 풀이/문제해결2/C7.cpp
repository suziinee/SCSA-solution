#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
struct AXIS { int x; int y; };
vector<AXIS> chk;


void input()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		chk.push_back({ x, y });
	}
}


void output(const int& ans)
{
	cout << ans;
}


int solve()
{
	int ans = 0;

	vector<int> diff; //현재 인덱스와 바로 전 인덱스와의 차이
	diff.push_back(0);
	for (int i = 1; i < n; i++) {
		diff.push_back(abs(chk[i].x - chk[i - 1].x) + abs(chk[i].y - chk[i - 1].y));
	}

	//1번째부터 n-2번째까지 해당 인덱스를 제거했을때 이득을 구함
	int max = -1 * 0x7fffffff; int idx;
	for (int i = 1; i < n - 1; i++) {
		int a1 = diff[i];
		int a2 = abs(chk[i].x - chk[i + 1].x) + abs(chk[i].y - chk[i + 1].y);
		int b1 = abs(chk[i - 1].x - chk[i + 1].x) + abs(chk[i - 1].y - chk[i + 1].y);

		if (a1 + a2 - b1 > max) {
			idx = i;
			max = a1 + a2 - b1;
		}
	}

	//idx를 제외하고 거리 구함
	for (int i = 0; i < n; i++) {
		if (i == idx) {
			ans += abs(chk[i - 1].x - chk[i + 1].x) + abs(chk[i - 1].y - chk[i + 1].y);
		}
		else if (i == idx + 1) continue;
		else ans += diff[i];
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