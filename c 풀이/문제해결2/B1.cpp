#include <iostream>
using namespace std;

int n;
int year[1250];


void input()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int sm, sd, em, ed;
		cin >> sm >> sd >> em >> ed;
		if (year[sm * 100 + sd] < (em * 100 + ed)) year[sm * 100 + sd] = em * 100 + ed;
	}
}

int solve()
{
	int ans = 0;
	
	int s = 1 * 100 + 1;
	int e = 3 * 100 + 1; 
	
	while (true) {
		int tmp = 0;
		for (int i = s; i <= e; i++) {
			if (year[i] > tmp) tmp = year[i];
		}

		//실패 체크
		if (e >= tmp) return 0; //tmp는 지는 날 하루 이후이므로 e==tmp여도 이어지지 않음
		
		ans++;
		if (tmp > 1130) return ans; //11/30까지 꽃이 피어있어야함
		s = e + 1;
		e = tmp;
	}
}

void output(const int& ans)
{
	cout << ans;
}


int main()
{
	input();
	int ans = solve();
	output(ans);
	return 0;
}