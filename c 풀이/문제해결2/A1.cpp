#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[100000];
int max1, max2;

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

void output()
{
	cout << max1 << " " << max2;
}

bool desc(int a, int b)
{
	return a > b;
}

void solve()
{
	//멍청한 다람쥐
	int *dp = new int[n];
	copy(arr, arr + n, dp);
	max1 = -1 * 0x7fffffff;
	for (int i = 0; i < n; i++) {
		if (i >= 1) {
			dp[i] = max({ dp[i - 1] + arr[i], dp[i] });
		}
		if (max1 < dp[i]) max1 = dp[i];
	}

	//똑똑한 다람쥐
	sort(arr, arr + n, desc);
	max2 = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] < 0) return;
		max2 += arr[i];
	}
}


int main()
{
	input();
	solve();
	output();
	return 0;
}
