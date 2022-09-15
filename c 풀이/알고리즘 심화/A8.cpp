#include <iostream>
#include <queue>
using namespace std;

int N;
struct COMP {
	bool operator()(const int& i1, const int& i2) { return i1 > i2; }
};
priority_queue<int, vector<int>, COMP> pq;


void input()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		pq.push(n);
	}
}

void solve()
{
	int ans = 0;

	while (pq.size() >= 2) {
		int n = pq.top(); pq.pop();
		int nn = pq.top(); pq.pop();

		ans += n + nn;
		pq.push(n + nn);
	}

	cout << ans;
}


int main(void)
{
	input();
	solve();
	return 0;
}