#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 10
int N;
int arr[MAXN + 5][MAXN + 5];
int chk[MAXN + 5];
int pick[MAXN + 5];
int ans = 0x7fffffff;
int route[MAXN + 5];


void input()
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
}

void dfs(int n) //depth만 파라미터로 가짐
{
	if (n > N) {
		int sum = 0; 
		//chk배열에서 1인 곳의 장소인 pick 배열에서 순서대로 꺼내기
		for (int i = 1; i <= N; i++) {
			sum += arr[i][pick[i]];
		}
		if (sum < ans) {
			ans = sum;
			copy(pick, pick + N + 1, route);
		}
		return;
	}

	for (int i = 1; i <= N; i++) { //장소
		if (chk[i] == 0) {
			chk[i] = 1; //chk에 체크하고
			pick[n] = i; //pick에 넣어주기
			dfs(n + 1);
			chk[i] = 0;
		}
	}
}

void solve()
{
	dfs(1);
	cout << ans << "\n";
	for (int i = 1; i <= N; i++) {
		cout << route[i] << " ";
	}
}


int main(void)
{
	input();
	solve();
	return 0;
}