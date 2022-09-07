#include <iostream>
using namespace std;

#define MAXN 5
int N, M; //주사위를 던지는 횟수, 모드
int pick[MAXN + 1]; //arr[n]은 n번째 던진 주사위에서 나온 숫자


void input()
{
	cin >> N >> M;
}

void dice1(int n)
{
	if (n > N) { //종료조건
		for (int i = 1; i <= N; i++) { cout << pick[i] << " "; }
		cout << "\n";
		return;
	}

	for (int i = 1; i <= 6; i++) { //n번째 주사위를 돌려서 i가 나온 상황
		pick[n] = i;
		dice1(n + 1); //n+1번째 주사위를 던짐
	}
}

void dice2(int n, int s)
{
	if (n > N) {
		for (int i = 1; i <= N; i++) { cout << pick[i] << " "; }
		cout << "\n";
		return;
	}

	for (int i = s; i <= 6; i++) {
		pick[n] = i;
		dice2(n + 1, i); //i부터 시작하면 됨
	}
}

int chk[7] = { 0 };
void dice3(int n)
{
	if (n > N) {
		for (int i = 1; i <= N; i++) { cout << pick[i] << " "; }
		cout << "\n";
		return;
	}

	for (int i = 1; i <= 6; i++) {
		if (chk[i] == 0) {
			pick[n] = i;
			chk[i] = 1;
			dice3(n + 1); 
			chk[i] = 0;
		}
	}
}


void solve()
{
	switch (M) {
	case 1:
		dice1(1);
		break;
	case 2: 
		dice2(1, 1); //시작지점 s 전달
		break;
	case 3:
		dice3(1); 
		break;
	}
}


int main(void)
{
	input();
	solve();
	return 0;
}