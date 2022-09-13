#include <iostream>
#include <vector>
using namespace std;

int sudo[9][9];
struct AXIS { int y; int x; };
vector<AXIS> blank;

int flag_r[9][10]; //flag_r[row] 해당 행에 0~9 숫자가 있는지
int flag_c[9][10];
int flag_small[9][10];


int small_num(const int& y, const int& x)
{
	if (x <= 2 && y <= 2) return 0;
	else if (x >= 3 && x <= 5 && y <= 2) return 1;
	else if (x >= 6 && x <= 8 && y <= 2) return 2;
	else if (y >= 3 && y <= 5 && x <= 2) return 3;
	else if (y >= 3 && y <= 5 && x >= 3 && x <= 5) return 4;
	else if (y >= 3 && y <= 5 && x >= 6 && x <= 8) return 5;
	else if (y >= 6 && y <= 8 && x <= 2) return 6;
	else if (y >= 6 && y <= 8 && x >= 3 && x <= 5) return 7;
	else if (y >= 6 && y <= 8 && x >= 6 && x <= 8) return 8;
}

void input()
{
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			cin >> sudo[y][x];
			if (sudo[y][x] == 0) blank.push_back({ y, x });
			else {
				flag_r[y][sudo[y][x]] = 1;
				flag_c[x][sudo[y][x]] = 1;
				
				int s = small_num(y, x);
				flag_small[s][sudo[y][x]] = 1;
			}
		}
	}
}

bool dfs(int n) //blank의 n번째 원소에 들어갈 숫자 고르기
{
	if (n >= blank.size()) return true;

	for (int i = 1; i <= 9; i++) {
		AXIS data = blank[n];

		if (flag_r[data.y][i]) continue;
		if (flag_c[data.x][i]) continue;
		int s = small_num(data.y, data.x);
		if (flag_small[s][i]) continue;

		flag_r[data.y][i] = 1;
		flag_c[data.x][i] = 1;
		flag_small[s][i] = 1;
		sudo[data.y][data.x] = i;

		if (dfs(n + 1)) return true;

		flag_r[data.y][i] = 0;
		flag_c[data.x][i] = 0;
		flag_small[s][i] = 0;
		sudo[data.y][data.x] = 0;
		
	}

	return false;
}

void solve()
{
	if (dfs(0)) {
		for (int y = 0; y < 9; y++) {
			for (int x = 0; x < 9; x++) {
				cout << sudo[y][x] << " ";
			}
			cout << "\n";
		}
	}
}


int main(void)
{
	input();
	solve();
	return 0;
}