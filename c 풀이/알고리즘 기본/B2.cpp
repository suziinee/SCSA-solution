#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int N;
struct MAT { int s; int b; };
vector<MAT> mat;
long long int ans = LONG_MAX; //일단 21억..


void input()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		int s, b;
		cin >> s >> b;
		mat.push_back({ s, b });
	}
}

bool dfs(int n, long long int s_sum, long long int b_sum, int cnt) //dfs를 행하던 중 만족하지 않으면 false를 리턴
{
	if (cnt > 0 && abs(s_sum - b_sum) < ans) {
		ans = abs(s_sum - b_sum);
	}
	if (n == N) return false; //종료조건은 뒤에 달기

	//n번째 재료 포함
	if (dfs(n + 1, s_sum * mat[n].s, b_sum + mat[n].b, cnt + 1)) return true;
	//n번째 재료 미포함
	if (dfs(n + 1, s_sum, b_sum, cnt)) return true;
	//둘 다 true가 아닐 경우
	return false;
}

void solve()
{
	dfs(0, 1, 0, 0);
	cout << ans;
}


int main(void)
{
	input();
	solve();
	return 0;
}