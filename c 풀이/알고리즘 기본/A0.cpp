#include <iostream>
#include <queue>
using namespace std;

#define MAX 100
struct AXIS { int y; int x; int time; };
int r, c;
AXIS st; AXIS en;
char map[MAX + 10][MAX + 10];


void input()
{
	cin >> c >> r;
	cin >> st.x >> st.y >> en.x >> en.y;
	for (int y = 1; y <= r; y++) {
		cin >> &map[y][1];
	}
}

void output(const int& ans)
{
	cout << ans;
}

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { -1, 0, 1, 0 };
int bfs()
{
	queue<AXIS> q;
	bool chk[MAX + 10][MAX + 10] = { false };

	q.push(st);
	chk[st.y][st.x] = true; st.time = 0;

	while (!q.empty()) {
		AXIS tmp = q.front(); q.pop();

		for (int dir = 0; dir < 4; dir++) {
			AXIS next;
			next.x = tmp.x + dx[dir];
			next.y = tmp.y + dy[dir];
			next.time = tmp.time + 1;

			if (next.x < 1 || next.y < 1 || next.x > c || next.y > r || map[next.y][next.x] == '1' || chk[next.y][next.x] == true) continue;

			if (next.x == en.x && next.y == en.y) return next.time;

			q.push(next);
			chk[next.y][next.x] = true;
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