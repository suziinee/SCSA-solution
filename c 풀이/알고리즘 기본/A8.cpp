#include <iostream>
#include <queue>
using namespace std;

#define MAX 100
int m, n; //세로, 가로
int map[MAX + 10][MAX + 10];
struct AXIS { int y; int x; int d; int order; };
AXIS st; AXIS en;
queue<AXIS> q;
bool chk[MAX + 10][MAX + 10][4]; //해당 좌표 해당 방향의 방문 여부


void input()
{
	cin >> m >> n;
	for (int y = 1; y <= m; y++) {
		for (int x = 1; x <= n; x++) {
			cin >> map[y][x];
		}
	}
	cin >> st.y >> st.x >> st.d >> en.y >> en.x >> en.d;
	
	switch (st.d) {
		case 1: st.d = 3; break;
		case 2: st.d = 1; break;
		case 3: st.d = 2; break;
		case 4: st.d = 0; break;
	}
	switch (en.d) {
		case 1: en.d = 3; break;
		case 2: en.d = 1; break;
		case 3: en.d = 2; break;
		case 4: en.d = 0; break;
	}
}

int bfs()
{
	q.push(st);
	st.order = 0;
	chk[st.y][st.x][st.d] = true;
	if (st.x == en.x&&st.y == en.y&&st.d == en.d) return st.order;

	while (!q.empty()) {
		AXIS data = q.front(); q.pop();

		//왼쪽 회전 : chk 배열 확인 -> 갱신 -> 종료조건 확인 -> 푸시
		AXIS left = data; 
		left.d = (data.d == 0) ? 3 : (data.d - 1);
		left.order = data.order + 1;
		if (chk[left.y][left.x][left.d] == false) {
			chk[left.y][left.x][left.d] = true;
			q.push(left);
			if (left.x == en.x&&left.y == en.y&&left.d == en.d) return left.order;
		}

		//오른쪽 회전
		AXIS right = data; 
		right.d = (data.d + 1) % 4;
		right.order = data.order + 1;
		if (chk[right.y][right.x][right.d] == false) {
			chk[right.y][right.x][right.d] = true;
			q.push(right);
			if (right.x == en.x&&right.y == en.y&&right.d == en.d) return right.order;
		}

		//앞으로 가기 : 한 칸 전진 -> 좌표 유효성 검증 -> chk 확인 -> 갱신 -> 종료조건 확인 -> 푸시
		const int dx[] = { 0, 1, 0, -1 };
		const int dy[] = { -1, 0, 1, 0 };
		AXIS ndata; 
		ndata.d = data.d;
		int tmp = data.order + 1;

		for (int i = 0; i < 100; i++) { //최대 100칸 앞으로 갈 수 있음
			ndata.x = data.x + dx[ndata.d];
			ndata.y = data.y + dy[ndata.d];

			if (ndata.x<1 || ndata.y<1 || ndata.x>n || ndata.y>m) break;
			if (map[ndata.y][ndata.x] == 1) break;

			if (chk[ndata.y][ndata.x][ndata.d] == false) {
				chk[ndata.y][ndata.x][ndata.d] = true;
				ndata.order = tmp;
				q.push(ndata);
				if (ndata.x == en.x&&ndata.y == en.y&&ndata.d == en.d) return tmp;
			}
			data = ndata;
		}
	}
}


void solve()
{
	int ans = bfs();
	cout << ans;
}


int main(void)
{
	input();
	solve();
	return 0;
}