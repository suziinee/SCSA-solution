#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
queue<int> q;
vector<int> ans;

void input()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
}

void output()
{
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
}


void solve()
{
	for (int i = 0; i < n - 1; i++) {
		int back = q.back() / 2;
		for (int j = 0; j < back; j++) {
			int tmp = q.front();
			q.pop();
			q.push(tmp);
		}
		ans.push_back(q.front());
		q.pop();
	}
	ans.push_back(q.front());
	q.pop();
}


int main()
{
	input();
	solve();
	output();
	return 0;
}