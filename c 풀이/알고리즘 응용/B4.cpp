#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int N;

struct COW {
	int n; //품종
	int x; //위치
	bool operator<(const COW& c) const {
		return x < c.x; //위치 오름차순 정렬
	}
};
vector<COW> cows;
unordered_set<int> all_n; //품종 저장


void input()
{
	cin >> N;
	int n, x;
	for (int i = 0; i < N; i++) {
		cin >> x >> n;
		cows.push_back({ n, x });
		if (all_n.find(n) == all_n.end()) all_n.insert(n);
	}
}

void solve()
{
	sort(cows.begin(), cows.end());

	unordered_set<int> chk;
	int ans = 0x7fffffff;
	int st = 0;
	int en = 0;
	chk.insert(cows[0].n);

	for (st = 0; st < N - 1; st++) {

		//품종이 다 찰때까지 en++
		while (en < N - 1 && chk.size() < all_n.size()) {
			en++;
			if (chk.find(cows[en].n) == chk.end()) chk.insert(cows[en].n);
		}

		//품종 다 찼거나 en=N
		if (chk.size() == all_n.size()) {
			ans = min(ans, cows[en].x - cows[st].x);
			bool flag = false;
			for (int i = st + 1; i <= en; i++) { //st와 같은 품종 있는지 확인
				if (cows[i].n == cows[st].n) { flag = true; break; }
			}
			if (!flag) chk.erase(cows[st].n); //같은 품종 없다면 지우기
			ans = min(ans, cows[en].x - cows[st].x);
		}
	}

	cout << ans;
}


int main()
{
	input();
	solve();
	return 0;
}