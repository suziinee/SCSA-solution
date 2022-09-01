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


int lower(const int& tar) //나보다 크거나 같은 값 중에서 가장 작은 인덱스 찾기
{
	int s = 0; int e = n - 1;
	int low = -1;
	
	while (s <= e) {
		int mid = (s + e) / 2;
		if (tar > leaf[mid]) s = mid + 1;
		else if (tar <= leaf[mid]) {
			low = mid;
			e = mid - 1;
		}
	}
	return low;
}


int upper(const int& tar) //나보다 작거나 같은 값 중에서 가장 큰 인덱스 찾기
{
	int s = 0; int e = n - 1;
	int up = -1;

	while (s <= e) {
		int mid = (s + e) / 2;
		if (tar < leaf[mid]) e = mid - 1;
		else if (tar >= leaf[mid]) {
			up = mid;
			s = mid + 1;
		}
	}
	return up;
}


void solve()
{
	sort(leaf.begin(), leaf.end());

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) { //next=leaf[j]
			int jump = leaf[j] - leaf[i]; //첫번째 뛰는 거리
			int low = lower(leaf[j] + jump);
			if (low == -1) {
				break;
			}
			else {
				int up = upper(leaf[j] + 2 * jump);
				ans += (up - low + 1);
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