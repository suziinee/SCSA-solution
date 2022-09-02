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


int check(const int& y) //해당 y에서 그릴 수 있는 최대 넓이 리턴
{
	int max = 0;
	for (int x = 0; x < 100; x++) {
		int h = 101;
		for (int c = x; c < 100; c++) { //x~c까지 최소 높이 구하기
			if (map[y][c] < h) h = map[y][c];
			if (h == 0) break; //해당 c에서 더이상 뒤로 나아갈 수 없음 (더이상 가로가 길어질 수 없음)
			if (max < (c - x + 1)*h) max = (c - x + 1)*h;
		}
	}
	return max;
}


void solve()
{
	//색칠하기
	for (int i = 0; i < n; i++) {
		color(paper[i].x, paper[i].y);
	}

	//각 x에 대해 y의 높이 구하기
	for (int x = 0; x < 100; x++) { 
		for (int y = 1; y < 100; y++) {
			if (map[y][x] == 1) map[y][x] += map[y - 1][x];
		}
	}

	//높이(y)를 지정해서 x~어느 지점까지 최소 높이를 구하기
	for (int y = 0; y < 100; y++) {
		int area = check(y);
		if (ans < area) ans = area;
	}
}


int main()
{
	input();
	solve();
	output();
	return 0;
}