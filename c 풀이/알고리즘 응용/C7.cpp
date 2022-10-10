#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAXN 100
#define MAXM 2000
int N, M;
int plot_cnt; //주차된 차들의 수
int plot[MAXN + 1]; //주차공간별 존재하는 차량 번호
int cost[MAXN + 1]; //주차공간별 단위무게당 요금
int car[MAXM + 1]; //차량별 무게

vector<int> inout;


void input()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
	}
	for (int i = 1; i <= M; i++) {
		cin >> car[i];
	}
	int n;
	for (int i = 0; i < 2 * M; i++) {
		cin >> n;
		inout.push_back(n);
	}
}

void solve()
{
	int ans = 0;
	queue<int> q; //대기하는 차 번호

	for (int i = 0; i < 2 * M; i++) {
		while (!q.empty() && plot_cnt < N) { //대기하는 차부터 넣어주기
			for (int j = 1; j <= N; j++) {
				if (plot[j] == 0) {
					plot[j] = q.front();
					plot_cnt++;
					ans += car[q.front()] * cost[j];
					q.pop();
					break;
				}
			}
		}

		if (inout[i] > 0) { //차가 들어옴
			if (plot_cnt < N) { //주차할 수 있음
				for (int j = 1; j <= N; j++) {
					if (plot[j] == 0) {
						plot[j] = inout[i];
						plot_cnt++;
						ans += car[inout[i]] * cost[j];
						break;
					}
				}
			}
			else {
				q.push(inout[i]);
			}
		}
		else { //차가 나감
			for (int j = 1; j <= N; j++) {
				if (plot[j] == (-inout[i])) {
					plot[j] = 0;
					plot_cnt--;
					break;
				}
			}
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