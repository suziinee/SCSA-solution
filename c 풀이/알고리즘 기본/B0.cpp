#include <iostream>
#include <vector>
using namespace std;

int k;
vector<int> S; //0번~k-1번 사용
int pick[7]; //1번~6번까지 사용


void output()
{
	for (int i = 1; i <= 6; i++) { cout << pick[i] << " "; }
	cout << "\n";
}

void dfs(int n, int s)
{
	if (n > 6) {
		output();
		return;
	}

	for (int i = s; i < k; i++) {
		pick[n] = S[i];
		dfs(n + 1, i + 1);
	}
}

void solve()
{
	//S집합에서 6개 조합 고르기
	dfs(1, 0);
}

int input()
{
	while (true) {
		S = {};
		cin >> k;
		if (k == 0) return 0;

		for (int i = 0; i < k; i++) {
			int a;
			cin >> a;
			S.push_back(a);
		}
		solve();
		cout << "\n";
	}
}


int main(void)
{
	int in = input();
	if (in == 0) return 0;
}