#include <iostream>
#include <queue>
using namespace std;

#define MAX 100
struct AXIS { int y; int x; };
int n, m;
AXIS st; AXIS en;


void input()
{
	cin >> n >> m;
	cin >> st.y >> st.x >> en.y >> en.x;
	st.y--; st.x--; en.y--; en.x--;
}

void output(const int& ans)
{
	cout << ans;
}

const int dx[] = { -1, 1, 2, 2, 1, -1, -2, -2 };
const int dy[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
int bfs()
{
	queue<AXIS> q;
	int chk[MAX + 10][MAX + 10] = { 0 };
	q.push(st);
	chk[st.y][st.x] = 1;
	
	while (!q.empty()) {
		AXIS tmp = q.front(); q.pop();

		for (int dir = 0; dir < 8; dir++) {
			int nx = tmp.x + dx[dir];
			int ny = tmp.y + dy[dir];

			if (nx < 0 || ny < 0 || nx >= m || ny >= n || chk[ny][nx] != 0) continue;

			chk[ny][nx] = chk[tmp.y][tmp.x] + 1;
			if (ny == en.y&&nx == en.x) return chk[ny][nx] - 1;
			q.push({ ny, nx });
		}
	}

	return 0;
}

int solve()
{
	int ans = bfs();
	return ans;
}


int main()
{
	input();
	int ans = solve();
	output(ans);
	return 0;
}