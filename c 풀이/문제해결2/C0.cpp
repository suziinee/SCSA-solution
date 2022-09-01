#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> leaf;
int ans;


void input()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		leaf.push_back(a);
	}
}


void output()
{
	cout << ans;
}


int search(const int& a, const int& b) //a <= () <= b를 leaf에서 찾아줌
{
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (leaf[i] >= a && leaf[i] <= b) cnt++;
	}
	return cnt;
}


void solve()
{
	sort(leaf.begin(), leaf.end());

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) { //next=leaf[j]
			int jump = leaf[j] - leaf[i]; //첫번째 뛰는 거리
			ans += search(leaf[j] + jump, leaf[j] + 2 * jump); 
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