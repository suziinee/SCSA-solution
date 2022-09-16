#include <iostream>
using namespace std;

int arr[6][3];

struct COMB { int a; int b; };
COMB comb[15] = { {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {1, 2}, {1, 3}, {1, 4}, {1, 5}, {2, 3}, {2, 4}, {2, 5}, {3, 4}, {3, 5}, {4, 5} };


bool dfs(int n)
{
	if (n == 15) return true;

	int t1 = comb[n].a; int t2 = comb[n].b;
	//t1 승리
	if (arr[t1][0] > 0 && arr[t2][2] > 0) {
		arr[t1][0]--; arr[t2][2]--;
		if (dfs(n + 1)) return true;
		arr[t1][0]++; arr[t2][2]++;
	}
	//t2 승리
	if (arr[t2][0] > 0 && arr[t1][2] > 0) {
		arr[t2][0]--; arr[t1][2]--;
		if (dfs(n + 1)) return true;
		arr[t2][0]++; arr[t1][2]++;
	}
	//무승부
	if (arr[t1][1] > 0 && arr[t2][1] > 0) {
		arr[t1][1]--; arr[t2][1]--;
		if (dfs(n + 1)) return true;
		arr[t1][1]++; arr[t2][1]++;
	}
	return false;
}


int solve(const int& total)
{
	//1. total이 30인지 확인
	if (total != 30) return 0;
	
	//2. dfs로 나머지 확인
	bool ret = dfs(0);
	return ret == true ? 1 : 0;
}


void input()
{
	for (int i = 0; i < 4; i++) {
		
		int total = 0;
		for (int y = 0; y < 6; y++) {
			for (int x = 0; x < 3; x++) {
				cin >> arr[y][x];
				if (arr[y][x]) total += arr[y][x];
			}
		}

		int ans = solve(total);
		cout << ans << " ";
	}
}


int main(void)
{
	input();
	return 0;
}