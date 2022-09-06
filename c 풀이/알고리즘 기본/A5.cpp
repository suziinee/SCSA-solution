#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX_N (100)
int N, M;
int mat[MAX_N + 1][MAX_N + 1];
int chk[MAX_N + 1]; //해당 상태의 최고의 결과 기록 (가장 최단시간)
struct STATUS { int n; int sum_time; };
queue<STATUS> q;
int path[MAX_N + 1];


void Input_Data(void) {
	cin >> N >> M;
	for (int n1 = 1; n1 <= N; n1++) {
		for (int n2 = 1; n2 <= N; n2++) {
			cin >> mat[n1][n2];
		}
	}
}

int BFS(void) {
	//chk에 높은 값 설정 -> 최대 100개 역이므로 최악의 경우 99번 역 이동 * 100
	fill(chk + 1, chk + N + 1, 0x7fffffff);

	q.push({ 1, 0 });
	chk[1] = 0;
	path[1] = 0;

	while (!q.empty()) {
		STATUS data = q.front(); q.pop();

		for (int i = 1; i <= N; i++) { //최고의 결과를 위해 이미 들린 1을 들를 필요가 없음
			STATUS ndata;
			ndata.n = i;
			ndata.sum_time = chk[data.n] + mat[data.n][i]; //data.sum_time이 아닌 data의 최고 경우로 다음 데이터 만들기
			
			if (chk[ndata.n] <= ndata.sum_time) continue; //새로 만든 데이터가 더 좋지 않으면 탈락
			
			//최고의 기록 갱신
			chk[ndata.n] = ndata.sum_time;
			path[ndata.n] = data.n;
			q.push(ndata);
		}
	}

	return chk[M];
}

void Print_Route(int n)
{
	if (n == 0) return;
	Print_Route(path[n]);
	cout << n << " ";
}


int main(void) 
{
	Input_Data();

	cout << BFS() << '\n';
	Print_Route(M);

	return 0;
}