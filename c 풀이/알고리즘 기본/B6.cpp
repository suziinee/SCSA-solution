#include <iostream>
using namespace std;

#define MAXN 12
int N;
int arr[MAXN + 3][MAXN + 3];
int chk[MAXN + 3];
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

void dfs(int n, int s, int sum) //n번째 경로를 뽑기
{
	if (sum > ans) return;
	if (n > N) {
		if (arr[s][1] == 0) return; //1번으로 돌아갈 수 없음
		if (sum + arr[s][1] < ans) ans = sum + arr[s][1];
		return;
	}

	for (int i = 2; i <= N; i++) {
		if (chk[i] == 0 && arr[s][i] > 0) {
			chk[i] = 1; //n번째 경로로 i를 뽑음
			dfs(n + 1, i, sum + arr[s][i]); //다음 경로를 i에서 시작할 것
			chk[i] = 0;
		}
	}
}

void solve()
{
	dfs(2, 1, 0);
	cout << ans;
}


int main(void)
{
	input();
	solve();
	return 0;
}