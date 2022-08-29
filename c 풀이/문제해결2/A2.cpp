#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 3000000
int n, d, k, c;
int rot[MAXN + 10];
int ans;
int used[3000 + 10];

void input()
{
	cin >> n;
	cin >> d;
	cin >> k;
	cin >> c;
	for (int i = 0; i < n; i++) {
		cin >> rot[i];
	}
}

void output()
{
	cout << ans;
}

void solve()
{
	used[c]++;
	int cnt = 0;

	//처음 k개는 used에 표시해놓기
	for (int i = 0; i < k; i++) {
		used[rot[i%n]]++;
	}
	for (int i = 1; i <= d; i++) {
		if (used[i] != 0) cnt++;
	}
	if (ans < cnt) ans = cnt;

	//sliding window
	for (int i = 1; i < n; i++) {
		int front = (i - 1) % n;
		int back = (i + k - 1) % n;

		if (used[rot[front]] != 0) {
			used[rot[front]]--;
			if (used[rot[front]]==0) cnt--;
		}

		if (used[rot[back]] == 0) cnt++;
		used[rot[back]]++;

		if (ans < cnt) ans = cnt;
	}
}


int main()
{
	input();
	solve();
	output();
	return 0;
}
