#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define MAX 300000

int n, k;
int name[MAX + 10];
int name_len[20 + 2];
long long int ans;

void input()
{
	cin >> n >> k;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		name[i] = str.length();
	}
}

void output()
{
	cout << ans / 2;
}

void solve()
{
	//초기값
	for (int i = 0; i <= min(n - 1, k); i++) {
		name_len[name[i]]++;
	}
	ans += name_len[name[0]] - 1; //자기자신은 빼기

	for (int i = 1; i < n; i++) {
		int front = i - k - 1;
		int back = i + k;
		if (front >= 0) {
			name_len[name[front]]--;
		}
		if (back < n) {
			name_len[name[back]]++;
		}
		ans += name_len[name[i]] - 1;
	}
}


int main()
{
	input();
	solve();
	output();
	return 0;
}
