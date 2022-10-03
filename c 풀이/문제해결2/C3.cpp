#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
long long int M;

int min_s = 0x7fffffff; int max_s = -1;
struct FOOD { int f; int s; };
vector<FOOD> food;


void input()
{
	cin >> N >> M;
	int f, s;
	for (int i = 0; i < N; i++) {
		cin >> f >> s;
		food.push_back({ f, s });
		if (s > max_s) max_s = s;
		if (s < min_s) min_s = s;
	}
}

bool check(int S) //연속해서 먹은 음식 중 매운 음식 단계의 최대가 S가 될 수 있는가?
{
	long long int sum_M = 0;
	for (int i = 0; i < N; i++) {
		if (food[i].s > S) sum_M = 0; //S를 넘어가면 sum_M 초기화하고 다시 더하기
		else {
			sum_M += food[i].f;
			if (sum_M >= M) return true;
		}
	}
	return false;
}

void solve()
{
	int ans; int mid;
	int st = min_s; int en = max_s;
	while (st <= en) {
		mid = (st + en) / 2;
		if (check(mid)) {
			ans = mid;
			en = mid - 1; //더 최소 찾으러 가기
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