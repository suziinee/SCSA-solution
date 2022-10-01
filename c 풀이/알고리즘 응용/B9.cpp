#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> money;


void input()
{
	cin >> N >> M;
	int n;
	for (int i = 0; i < N; i++) {
		cin >> n;
		money.push_back(n);
	}
}

bool check(int m) //한번 인출 금액 m원
{
	int cur = 0; int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (money[i] > cur) { //넣었다가 다시 인출
			cnt++;
			cur = m;
			cur -= money[i];
			if (cur < 0) return false;
		}
		else { //그냥 cur에서 사용
			cur -= money[i];
		}
	}
	if (cnt <= M) return true;
	return false;
}

void solve()
{
	int ans; int mid;
	int st = 0; int en = 100000; //1만보다 더 많이 인출할 수도 있긴함
	while (st <= en) {
		mid = (st + en) / 2;
		if (check(mid)) { //mid원으로 가능
			ans = mid;
			en = mid - 1; //더 최솟값 찾으러 가기
		}
		else {
			st = mid + 1;
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