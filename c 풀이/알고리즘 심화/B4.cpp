#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct COMP_SMALLER {
	bool operator()(long long int& i1, long long int& i2) { return i1 > i2; }
};
priority_queue<long long int, vector<long long int>, COMP_SMALLER> big_pq;
vector<long long int> nums;


void solve()
{
	nums.push_back(1);
	int ugly[3] = { 2, 3, 5 };
	int nums_index = 0;

	while (nums.size() < 1500) {
		long long int n = nums[nums_index];

		for (int i = 0; i < 3; i++) {
			big_pq.push(n * ugly[i]);
		}

		while (big_pq.top() == n) {
			big_pq.pop();
		}

		nums.push_back(big_pq.top()); big_pq.pop();
		nums_index++;
	}
}

void input()
{
	solve();
	int n;
	while (true) {
		cin >> n;
		if (n == 0) return;
		cout << nums[n - 1] << "\n";
	}
}


int main(void)
{
	input();
	return 0;
}