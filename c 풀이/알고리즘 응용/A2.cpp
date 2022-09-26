#include <iostream>
using namespace std;

#define MAXB 9
#define MAXN 100000
int B, N;
int prefix[MAXN + 1];

int boat[MAXB];
int chk[MAXB];
int b_sum;
int ans = -1;


void input()
{
	cin >> B >> N;

	for (int i = 0; i < B; i++) {
		cin >> boat[i];
		b_sum += boat[i];
	}
	int p;
	for (int i = 1; i <= N; i++) {
		cin >> p;
		prefix[i] = prefix[i - 1] + p;
	}
}

int binary_search(int st, int en, int tar) //tar보다 작거나 같은 숫자의 가장 큰 인덱스
{
	int ret = -1; int mid;
	while (st <= en) {
		mid = (st + en) / 2;
		if (tar >= prefix[mid]) {
			st = mid + 1;
			ret = mid;
		}
		else {
			en = mid - 1;
		}
	}
	return ret;
}

void dfs(int n, int remain)
{
	if (n == N + 1) { //승객을 다 태움
		if (ans < remain) ans = remain;
		return;
	}
	if (remain == 0) return; //배가 부족함

	for (int i = 0; i < B; i++) {
		if (chk[i] == 0) {
			int last_pass = binary_search(n - 1, N, prefix[n - 1] + boat[i]);
			chk[i] = 1;
			dfs(last_pass + 1, remain - boat[i]);
			chk[i] = 0;
		}
	}
}

void solve()
{
	dfs(1, b_sum);
	cout << ans;
}


int main()
{
	input();
	solve();
	return 0;
}