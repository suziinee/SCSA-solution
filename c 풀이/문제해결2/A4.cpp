#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int map[100][100];
struct AXIS {
	int x; int y;
};
vector<AXIS> paper;
int ans = 100;


void input()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		AXIS p;
		cin >> p.x >> p.y;
		paper.push_back(p);
	}
}


void output()
{
	cout << ans;
}


void color(const int& x, const int& y)
{
	for (int i = y; i < y + 10; i++) {
		for (int j = x; j < x + 10; j++) {
			if (map[i][j] == 0) map[i][j] = 1;
		}
	}
}


//(x, y)부터 (i, j)까지 black인지 확인
int is_black(const int& x, const int& y, const int& i, const int& j)
{
	for (int p = y; p <= j; p++) {
		for (int q = x; q <= i; q++) {
			if (map[p][q] == 0) return 0;
		}
	}
	return 1;
}


void check(const int& x, const int& y)
{
	for (int i = x; i < 100; i++) {
		if (map[y][i] == 0) return;
		for (int j = y; j < 100; j++) {
			if (map[j][i] == 0) break;
			if (ans >= (i - x + 1)*(j - y + 1)) continue;
			if (is_black(x, y, i, j)) ans = max({ ans, (i - x + 1)*(j - y + 1) });
		}
	}
}


void solve()
{
	//색칠하기
	for (int i = 0; i < n; i++) {
		color(paper[i].x, paper[i].y);
	}

	for (int y = 0; y < 100; y++) {
		for (int x = 0; x < 100; x++) {
			if (map[y][x] == 1) check(x, y);
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