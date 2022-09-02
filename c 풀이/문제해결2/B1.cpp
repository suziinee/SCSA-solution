#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
struct FLOWER {
	int start; int end;
};
vector<FLOWER> flo;
int ans;
int flag = 0;


void input()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		flo.push_back({ a * 100 + b, c * 100 + d });
	}
}


void output()
{
	if (flag == 1) cout << 0;
	else cout << ans;
}


bool compare(const FLOWER& f1, const FLOWER& f2)
{
	return f1.start < f2.start;
}


void solve()
{
	sort(flo.begin(), flo.end(), compare);
	
	int start = 3 * 100 + 1;
	int i = 0;

	while (true) {
		int maxend = 0;
		//day날까지 피는 날 중에 가장 늦게 지는 꽃 선택
		while (i < n && flo[i].start <= start) {
			if (flo[i].end > maxend) maxend = flo[i].end;
			i++;
		}

		//실패 체크*** => 고른 maxend가 시작 날짜보다 작으면 이어지지 않음 + 굳이 i==n 체크 안해도됨
		if (maxend < start) { flag = 1; return; }
		//실패가 아니라면 꽃 개수 증가
		ans++;
		//성공 체크
		if (maxend > 1130) return;
		//start 갱신
		start = maxend;
	}
}


int main()
{
	input();
	solve();
	output();
	return 0;
}