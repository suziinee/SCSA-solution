#include <iostream>
#include <stack>
using namespace std;

int n;
stack<int> s;
int ans;

void input()
{
	cin >> n;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		s.push(b);
	}
}

void output()
{
	cout << ans;
}


void solve()
{
	while (!s.empty()) {
		int tmp = s.top(); s.pop();
		ans++;

		while (true) {
			if (s.empty()) break;
			if (s.top() > tmp) {
				s.pop();
			}
			else {
				break;
			}
		}
	}
}


int main()
{
	input();
	solve();
	output();
	return 0;
}
