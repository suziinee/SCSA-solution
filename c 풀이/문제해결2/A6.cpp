#include <iostream>
using namespace std;

int n;
int ans;

void input()
{
	cin >> n;
}

void output()
{
	cout << ans;
}

void solve()
{
	const int coin[] = { 500, 100, 50, 10 };
	int i = 0;
	while (n) {
		ans += n / coin[i];
		n %= coin[i];
		i++;
	}
}


int main()
{
	input();
	solve();
	output();
	return 0;
}
