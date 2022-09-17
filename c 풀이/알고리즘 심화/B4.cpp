#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
using namespace std;

struct COMP_SMALLER {
	bool operator()(long long int& i1, long long int& i2) { return i1 > i2; }
};
struct COMP_BIGGER {
	bool operator()(long long int& i1, long long int& i2) { return i1 < i2; }
};

priority_queue<long long int, vector<long long int>, COMP_SMALLER> big_pq;
priority_queue<long long int, vector<long long int>, COMP_BIGGER> small_pq;


void solve(int n)
{
	//초기화
	small_pq = {};
	big_pq = {};

	small_pq.push(1);
	int ugly[3] = { 2, 3, 5 };

	while (true) {
		if (small_pq.size() >= n) break;

		for (int i = 0; i < 3; i++) {
			big_pq.push(small_pq.top() * ugly[i]);
		}

		while (big_pq.top() == small_pq.top()) {
			big_pq.pop();
		}

		small_pq.push(big_pq.top()); big_pq.pop();
	}
}

void input()
{
	int n;
	while (true) {
		cin >> n;
		if (n == 0) return;
		solve(n);
		cout << small_pq.top() << "\n";
	}
}


int main(void)
{
	input();
	return 0;
}