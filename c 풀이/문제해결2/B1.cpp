#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
struct DAY {
	int m; int d;
};
struct FLOWER {
	DAY start; DAY end;
};
vector<FLOWER> flo;
int ans;
int flag = 0;

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		FLOWER f;
		cin >> f.start.m >> f.start.d >> f.end.m >> f.end.d;
		flo.push_back(f);
	}
}

void output()
{
	if (flag == 1) cout << 0;
	else cout << ans;
}

bool compare(const FLOWER& f1, const FLOWER& f2)
{
	if (f1.start.m == f2.start.m) {
		return f1.start.d < f2.start.d;
	}
	else {
		return f1.start.m < f2.start.m;
	}
}

int day_compare(const DAY& d1, const DAY& d2) //d1이 크면 1, d2가 크면 2
{
	if (d1.m < d2.m) return -1;
	if (d1.m > d2.m) return 1;
	if (d1.m == d2.m) {
		if (d1.d < d2.d) return -1;
		else if (d1.d > d2.d) return 1;
		else return 0;
	}
}

void solve()
{
	sort(flo.begin(), flo.end(), compare);

	DAY day;
	day.m = 3; day.d = 2;
	DAY end;
	end.m = 11; end.d = 30;

	int i = 0;
	if (day_compare(flo[i].start, day) != -1) {
		flag = 1;
		return;
	}
	while (true) {

		DAY tmp = day;
		while (true) {
			//종료조건
			if (day_compare(tmp, end) != -1) {
				ans++;
				return;
			}
			if (i >= n) {
				flag = 1;
				return;
			}
			
			if (day_compare(flo[i].start, day) == -1) { //start 날짜가 day 앞쪽에 있으면 tmp 갱신
				if (day_compare(flo[i].end, tmp) == 1) {
					tmp = flo[i].end;
				}
			}
			else { //start 날짜가 day 뒤쪽에 있으면
				//tmp를 day로 갱신 후 탈출
				day = tmp;
				ans++;
				break;
			}
			i++;
		}
	}
}


int main()
{
	input();
	solve();
	output();
	return 0;
}