#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int T, N, K;
int min_p; int max_p;
unordered_map<int, int> ht; //<위치, 수익>


void solve()
{
	//min_p로 초기값 형성
	int ans = 0; int sum = 0;
	for (int i = min_p - K; i <= min_p + K; i++) {
		if (ht.find(i) != ht.end()) { //해당 위치에 보석이 있었음
			sum += (ht.find(i))->second;
		}
	}
	ans = max(ans, sum);

	for (int i = min_p + 1; i <= max_p; i++) {
		auto it1 = ht.find(i + K);
		auto it2 = ht.find(i - K - 1);
		
		//i+K는 넣고
		if (it1 != ht.end()) { //해당 위치에 보석이 있었음
			sum += it1->second; //더함
		}

		//i-K-1은 뺀다
		if (it2 != ht.end()) { //해당 위치에 보석이 있었음
			sum -= it2->second; //뺌
		}
		ans = max(ans, sum);
	}
	cout << ans << "\n";
}

void input()
{
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> K;

		//초기화
		ht.clear();
		min_p = 0x7fffffff; max_p = -1;

		int v, p;
		for (int i = 0; i < N; i++) {
			cin >> v >> p;
			ht.insert({ p, v });
			if (p > max_p) max_p = p;
			if (p < min_p) min_p = p;
		}

		solve();
	}
}


int main()
{
	input();
	return 0;
}