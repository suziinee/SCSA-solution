#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 10
int N;
int arr[MAXN + 5][MAXN + 5];
int chk[MAXN + 5];
int ans = 0x7fffffff;


void input()
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
}

void dfs(int n, int sum) //depth, sum
{
	if (n > N) {
		if (sum < ans) ans = sum;
		return;
	}

	for (int i = 1; i <= N; i++) { //장소
		if (chk[i] == 0) {
			chk[i] = 1; //n번째 알파벳의 i번째 장소를 선택할 것
			sum += arr[n][i];
			dfs(n + 1, sum);
			chk[i] = 0;
			sum -= arr[n][i];
		}
	}
}

void solve()
{
	dfs(1, 0);
	cout << ans << "\n";
}


int main(void)
{
	input();
	solve();
	return 0;
}