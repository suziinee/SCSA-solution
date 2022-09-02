#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
struct AXIS { int x; int y; };
vector<AXIS> pnt;


void input()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		pnt.push_back({ x, y });
	}
}


void output(const int& ans)
{
	cout << ans;
}


int solve()
{
	int ans = 0;

	int max = -1 * 0x7fffffff;
	int max_idx;

	vector<int> diff; diff.push_back(0);
	for (int i = 1; i < n - 1; i++) {

		int a1 = abs(pnt[i].x - pnt[i - 1].x) + abs(pnt[i].y - pnt[i - 1].y);
		int a2 = abs(pnt[i].x - pnt[i + 1].x) + abs(pnt[i].y - pnt[i + 1].y);
		int b1 = abs(pnt[i + 1].x - pnt[i - 1].x) + abs(pnt[i + 1].y - pnt[i - 1].y);
		
		diff.push_back(a1);
		if ((a1 + a2) - (b1) > max) {
			max_idx = i;
			max = a1 + a2 - b1;
		}
	}
	diff.push_back(abs(pnt[n - 2].x - pnt[n - 1].x) + abs(pnt[n - 2].y - pnt[n - 1].y));

	//max_idx 지점의 체크포인트를 빼고 달리는 거리 계산
	for (int i = 0; i < diff.size(); i++) {
		if (i == max_idx) {
			ans += abs(pnt[max_idx + 1].x - pnt[max_idx - 1].x) + abs(pnt[max_idx + 1].y - pnt[max_idx - 1].y);
		}
		else if (i == max_idx + 1) continue;
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