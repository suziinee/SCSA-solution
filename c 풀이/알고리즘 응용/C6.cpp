#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int N1, N2, N3;
unordered_map<int, int> m;

void input()
{
	cin >> N1 >> N2 >> N3;
}

bool compare(const pair<int, int>& i1, const pair<int, int>& i2) {
	if (i1.second == i2.second) return i1.first < i2.first;
	return i1.second > i2.second;
}

void solve()
{
	for (int i = 1; i <= N1; i++) {
		for (int j = 1; j <= N2; j++) {
			for (int k = 1; k <= N3; k++) {
				int sum = i + j + k;
				if (m.find(sum) == m.end()) {
					m.insert({ sum, 1 });
				}
				else {
					m[sum]++;
				}
			}
		}
	}

	vector<pair<int, int>> vec(m.begin(), m.end());
	sort(vec.begin(), vec.end(), compare);
	cout << vec[0].first;
}


int main()
{
	input();
	solve();
	return 0;
}