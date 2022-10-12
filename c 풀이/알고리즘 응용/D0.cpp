#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int ans;

struct AXIS { int y, x; };
vector<AXIS> robot;
vector<AXIS> cookie;
bool chk[10];


void dfs(int n, int sum_dist)
{
	if (n == N) {
		if (sum_dist < ans) ans = sum_dist;
		return;
	}
	if (sum_dist >= ans) return;

	for (int i = 0; i < N; i++) { //n번 로봇이 먹을 과자 i번
		if (chk[i]) continue;
		int dist = abs(robot[n].y - cookie[i].y) + abs(robot[n].x - cookie[i].x);
		chk[i] = true;
		dfs(n + 1, sum_dist + dist);
		chk[i] = false;
	}
}

void input()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		robot.clear();
		cookie.clear();
		fill(chk, chk + 10, false);
		ans = 0x7fffffff;
		int y, x;
		for (int i = 0; i < N; i++) {
			cin >> y >> x;
			cookie.push_back({ y, x });
		}
		for (int i = 0; i < N; i++) {
			cin >> y >> x;
			robot.push_back({ y, x });
		}
		dfs(0, 0);
		cout << ans << "\n";
	}
}


int main()
{
	input();
	return 0;
}