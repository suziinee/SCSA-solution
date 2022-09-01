#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n;
vector<int> arr;
int t;
vector<int> target;
vector<int> ans;


void input()
{
	cin >> n;
	arr.push_back(0); //0번째 인덱스
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		arr.push_back(a);
	}
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a;
		target.push_back(a);
	}
}


void output()
{
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
}


void binary_search(const int& tar)
{
	int s = 1; int e = n;

	while (true) {
		//실패조건
		if (s > e) {
			ans.push_back(0);
			return;
		}

		int mid = (s + e) / 2;
		if (tar == arr[mid]) {
			ans.push_back(mid);
			return;
		}
		else if (tar == arr[s]) {
			ans.push_back(s);
			return;
		}
		else if (tar == arr[e]) {
			ans.push_back(e);
			return;
		}
		else if (tar < arr[mid]) {
			e = mid - 1;
			continue;
		}
		else if (tar > arr[mid]) {
			s = mid + 1;
			continue;
		}
	}
}


void solve()
{
	for (int i = 0; i < t; i++) {
		binary_search(target[i]);
	}
}


int main()
{
	input();
	solve();
	output();
	return 0;
}