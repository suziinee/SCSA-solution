#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAXN 100
int max_dist;
int n;

//번호, 뒤거리, 정비 시간
struct STN { int n; int b_dist; int val; }; 
queue<STN> q;
int chk[MAXN + 2]; //n+1번이 end, 해당 상태까지 최소 방문 시간
int path[MAXN + 2];
vector<STN> stn;


void input()
{
	cin >> max_dist >> n;

	//0번 정비소 (시작지점)
	for (int i = 0; i <= n; i++) {
		int a;
		cin >> a;
		stn.push_back({ i, a, 0 }); //val은 비워두기
	}
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		stn[i].val = a;
	}
	stn.push_back({ n + 1, 0, 0 }); //n+1번 정비소 (끝지점)
}

int bfs()
{
	fill(chk, chk + n + 2, 0x7fffffff); //0번부터 n+1번까지 사용 예정
	q.push({ stn[0] }); 
	chk[0] = 0;

	while (!q.empty()) {
		STN data = q.front(); q.pop();

		//바로 뒤 정비소부터(data.n + 1) n+1 정비소까지 max_dist 내에 있는 정비소들 탐색
		int i = data.n + 1;
		int sum_dist = data.b_dist;
		while (i <= (n + 1) && sum_dist <= max_dist) {
			STN ndata = stn[i];
			if (chk[ndata.n] > chk[data.n] + ndata.val) {
				chk[ndata.n] = chk[data.n] + ndata.val;
				path[ndata.n] = data.n;
				q.push(ndata);
			}
			i++;
			sum_dist += ndata.b_dist;
		}
	}

	return chk[n + 1];
}

vector<int> route;
void search_route(int n)
{
	if (n == 0) return;
	search_route(path[n]);
	route.push_back(n);
}

void solve()
{
	int ans = bfs();

	if (ans == 0) {
		cout << 0;
		return;
	}

	cout << ans << "\n";
	search_route(n + 1);
	cout << route.size() - 1 << "\n";
	for (int i = 0; i < route.size() - 1; i++) {
		cout << route[i] << " ";
	}
}


int main(void)
{
	input();
	solve();
	
	return 0;
}