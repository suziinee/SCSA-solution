#include <iostream>
#include <vector>
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

void height(const AXIS& a)
{
	int now = -1; int sum = 0;

	for (int x = a.x; x < a.x + 10; x++) {
		int tmp = 0; //매 x마다 y의 누적을 구함
		for (int y = a.y + 10 - 1;; y--) {
			if (map[y][x] == 1) tmp++;
			else break;
		}
		if (now == -1) { //초기 tmp 설정
			now = tmp;
			sum += tmp;
		}
		else {
			if (now == tmp) sum += tmp;
			else {
				if (sum > ans) ans = sum;
				sum = 0;
				now = tmp; sum += tmp;
			}
		}
	}
	if (sum > ans) ans = sum;
}

void width(const AXIS& a)
{
	int now = -1; int sum = 0;

	for (int y = a.y; y < a.y + 10; y++) {
		int tmp = 0; //매 y마다 x의 누적을 구함
		for (int x = a.x; ; x++) {
			if (map[y][x] == 1) tmp++;
			else break;
		}
		if (now == -1) { //초기 tmp 설정
			now = tmp;
			sum += tmp;
		}
		else {
			if (now == tmp) sum += tmp;
			else {
				if (sum > ans) ans = sum;
				sum = 0;
				now = tmp; sum += tmp;
			}
		}
	}
	if (sum > ans) ans = sum;
}

void solve()
{
	//색칠하기
	for (int i = 0; i < n; i++) {
		color(paper[i].x, paper[i].y);
	}

	for (int i = 0; i < n; i++) {
		height(paper[i]);
		width(paper[i]);
	}
}


int main()
{
	input();
	solve();
	output();
	return 0;
}