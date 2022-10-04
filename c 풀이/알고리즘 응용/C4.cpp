#include <iostream>
#include <vector>
using namespace std;

int T, N, M;

struct MONKEY { int a; int b; };
vector<MONKEY> N_monkey;
vector<MONKEY> M_monkey;


void input()
{
	cin >> T >> N;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		N_monkey.push_back({ a, b });
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		M_monkey.push_back({ a, b });
	}
}

bool simul(int time) //해당 시간이 가능한지 판단
{
	int N_coco = 0;
	for (MONKEY m : N_monkey) {
		if (time >= m.a) {
			N_coco += (time - m.a) / m.b + 1;
		}
	}
	int M_coco = 0;
	for (MONKEY m : M_monkey) {
		if (T - time >= m.a) {
			M_coco += (T - time - m.a) / m.b + 1;
		}
	}

	if (N_coco <= M_coco) return true; //시간 길게하기
	else if (N_coco > M_coco) return false; //시간 짧게하기
}

void solve()
{
	int ans; int mid;
	int st = 0; int en = T; //시간
	while (st <= en) {
		mid = (st + en) / 2;
		if (simul(mid)) {
			st = mid + 1;
			ans = mid;
		}
		else {
			en = mid - 1;
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