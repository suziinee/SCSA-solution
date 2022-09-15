#include <iostream>
#include <queue>
using namespace std;

int N;
struct COMP_BIGGER {
	bool operator()(const int& i1, const int& i2) { return i1 < i2; }
};
struct COMP_SMALLER {
	bool operator()(const int& i1, const int& i2) { return i1 > i2; }
};
priority_queue<int, vector<int>, COMP_BIGGER> small_pq;
priority_queue<int, vector<int>, COMP_SMALLER> big_pq;


void solve() 
{
	cin >> N;
	
	int n;
	cin >> n;
	small_pq.push(n);
	cout << small_pq.top() << "\n";

	for (int i = 0; i < (N - 1); i++) {
		cin >> n;

		if (n <= small_pq.top()) small_pq.push(n);
		else big_pq.push(n);

		if (small_pq.size() < big_pq.size()) {
			small_pq.push(big_pq.top());
			big_pq.pop();
		}
		else if (small_pq.size() > big_pq.size() + 1) {
			big_pq.push(small_pq.top());
			small_pq.pop();
		}

		if (i % 2 == 1) cout << small_pq.top() << "\n";
	}
}


int main(void)
{
	solve();
	return 0;
}