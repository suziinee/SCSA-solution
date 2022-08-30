#include <iostream>
using namespace std;

int w;
int coin[6];
int c[6] = { 500, 100, 50, 10, 5, 1 };
int ans;

void input()
{
	cin >> w;
	for (int i = 0; i < 6; i++) {
		cin >> coin[i];
	}
}

void output()
{
	cout << ans << "\n";
	for (int i = 0; i < 6; i++) {
		cout << coin[i] << " ";
	}
}

void solve()
{
	int sum = 0;
	for (int i = 0; i < 6; i++) {
		sum += c[i] * coin[i];
	}

	int n = sum - w;
	for (int i = 0; i < 6; i++) {
		if (n / c[i] <= coin[i]) {
			coin[i] -= n / c[i];
			n %= c[i];
		}
		else {
			n -= c[i] * coin[i];
			coin[i] = 0;
		}
		ans += coin[i];
	}
}


int main()
{
	input();
	solve();
	output();
	return 0;
}