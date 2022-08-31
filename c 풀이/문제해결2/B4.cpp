#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n;
vector<int> h;
vector<int> ans;

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		h.push_back(a);
		ans.push_back(0);
	}
}

void output()
{
	for (int i = 0; i < n; i++) {
		cout << ans[i] << "\n";
	}
}


void solve()
{
	stack<int> s; //index를 담기

	for (int i = 0; i < n; i++) {
		while (!s.empty() && h[s.top()] < h[i]) {
			ans[s.top()] = i + 1;
			s.pop();
		}
		s.push(i);
	}
}


int main()
{
	input();
	solve();
	output();
	return 0;
}