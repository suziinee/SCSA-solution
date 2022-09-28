#include <iostream>
#include <deque>
using namespace std;

#define MAXN 500000
int N, K;
int nums[MAXN];
deque<int> dq;


void input()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		scanf_s("%1d", &nums[i]);
	}
}

void solve()
{
	for (int i = 0; i < N; i++) {
		while (!dq.empty() && K > 0 && dq.back() < nums[i]) {
			dq.pop_back();
			K--;
		}
		dq.push_back(nums[i]);
	}

	if (K) {
		for (int i = 0; i < K; i++) dq.pop_back();
	}

	//for (int i = 0; i < N - K; i++) cout << dq[i];
	for (int n : dq) cout << n;
}


int main()
{
	input();
	solve();
	return 0;
}