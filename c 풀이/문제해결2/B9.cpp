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
		cout << ans[i] << " ";
	}
}


int lower(const int& tar)
{
	int low = -1;
	int s = 0; int e = n - 1;
	
	while (s <= e) {
		int mid = (s + e) / 2;
		if (tar < arr[mid]) e = mid - 1;
		else if (tar > arr[mid]) s = mid + 1;
		else if (tar == arr[mid]) {
			low = mid;
			e = mid - 1;
		}
	}
	return low;
}


int upper(const int& tar)
{
	int high = -1;
	int s = 0; int e = n - 1;

	while (s <= e) {
		int mid = (s + e) / 2;
		if (tar < arr[mid]) e = mid - 1;
		else if (tar > arr[mid]) s = mid + 1;
		else if (tar == arr[mid]) {
			high = mid;
			s = mid + 1;
		}
	}
	return high;
}


void solve()
{
	for (int i = 0; i < t; i++) {
		int low = lower(target[i]);
		if (low == -1) ans.push_back(0);
		else {
			int high = upper(target[i]);
			ans.push_back(high - low + 1);
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