#include <iostream>
using namespace std;

#define MAXB 9
#define MAXN 100000
int B, N;
int prefix[MAXN + 1];

int boat[MAXB];
int pick[MAXB];
int chk[MAXB];
int ans = -1;


void input()
{
	cin >> B >> N;

	for (int i = 0; i < B; i++) {
		cin >> boat[i];
	}
	int p;
	for (int i = 1; i <= N; i++) {
		cin >> p;
		prefix[i] = prefix[i - 1] + p;
	}
}

int binary_search(int st, int en, int tar) //tar보다 작거나 같은 숫자의 가장 큰 인덱스
{
	int ret = 0; int mid;
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

int check()
{
	int idx = 1; int i;
	for (i = 0; i < B; i++) {
		idx = binary_search(idx - 1, N, prefix[idx - 1] + pick[i]); //idx 번째까지 승객 태움
		if (idx == N) { //i번째 배까지 승객을 다 태움
			break;
		}
		idx++;
	}

	if (idx == N) {
		int sum = 0;
		for (int j = i + 1; j < B; j++) sum += pick[j];
		return sum;
	}
	else return -1;
}

void dfs(int n)
{
	if (n == B) {
		int ret = check();
		if (ret != -1 && ret > ans) ans = ret;
		return;
	}

	for (int i = 0; i < B; i++) {
		if (chk[i] == 0) {
			pick[n] = boat[i];
			chk[i] = 1;
			dfs(n + 1);
			pick[n] = 0;
			chk[i] = 0;
		}
	}
}

void solve()
{
	dfs(0);
	cout << ans;
}


int main()
{
	input();
	solve();
	return 0;
}