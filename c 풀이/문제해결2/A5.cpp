#include <iostream>
#include <vector>
using namespace std;

#define MAX 10000
int n, t, m;
int map[MAX + 10][MAX + 10];
int ans;

void input()
{
	cin >> n >> t >> m;
	for (int i = 0; i < m; i++) {
		int y, x;
		cin >> y >> x;
		map[y][x] = 1;
	}
}

void output()
{
	cout << ans;
}

void check(int* res)
{
	for (int y = 1; y <= n - res[0]; y++) {
		int tmp = 0; //해당 y행에서 먹을 수 있는 물고기
		for (int x = 1; x <= n - res[1]; x++) {
			if (x == 1) { //처음에는 초기화
				for (int i = y; i <= y + res[0]; i++) {
					for (int j = 1; j <= 1 + res[1]; j++) {
						if (map[i][j] == 1) tmp++;
					}
				}
			}
			else { //나머지는 sliding windows
				for (int i = y; i <= y + res[0]; i++) {
					if (map[i][x - 1] == 1) tmp--;
					if (map[i][x + res[1]] == 1) tmp++;
				}
			}
			if (ans < tmp) ans = tmp; //매번 update
		}
	}
}


void solve()
{
	int res[2];
	for (int i = 1; i < (t / 2); i++) {
		res[0] = i;
		res[1] = (t / 2) - i;
		check(res);
	}
}


int main()
{
	input();
	solve();
	output();
	return 0;
}
