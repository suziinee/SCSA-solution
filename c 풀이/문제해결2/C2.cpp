#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> tree;
int ans;


void input()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		tree.push_back(a);
	}
}


void output()
{
	cout << ans;
}


void solve()
{
	sort(tree.begin(), tree.end());

	long long int sum = tree[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		sum += tree[i];
		int cut_tree = n - i; //잘려진 나무의 수
		int rest = sum - (tree[i] * cut_tree); //자르고 남은 나무 길이
		if (rest == m) { //tree[i]가 정답
			ans = tree[i];
			return;
		}
		else if (rest > m) { //tree[i]+1~tree[i+1]-1 사이에 정답이 있음
			ans = (rest - m) / (cut_tree - 1) + tree[i];
			return;
		}
		
	}
	if (ans == 0) { //모두 같은 크기의 나무
		ans = tree[n - 1] - (m / n);
		return;
	}
}


int main()
{
	input();
	solve();
	output();
	return 0;
}