#include <iostream>
#include <queue>
using namespace std;

#define MAX 100
struct AXIS { int x; int y; };
int X, Y;
AXIS st; 
char map[MAX + 10][MAX + 10];

void input()
{
	cin >> X >> Y;
	for (int y = 0; y < Y; y++) {
		cin >> &map[y][0];
	}
	cin >> st.x >> st.y;
	st.x--; st.y--;
}

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { -1, 0, 1, 0 };
void bfs()
{
	queue<AXIS> q;
	int chk[MAX + 10][MAX + 10] = { 0 };
	q.push(st);
	chk[st.y][st.x] = 3;
	
	while (!q.empty()) {
		AXIS tmp = q.front(); q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = tmp.x + dx[dir];
			int ny = tmp.y + dy[dir];

			if (nx < 0 || ny < 0 || nx >= X || ny >= Y || chk[ny][nx] != 0 || map[ny][nx] == '0') continue;

			chk[ny][nx] = chk[tmp.y][tmp.x] + 1;
			q.push({ nx, ny });
		}
	}

	int max = -1; int undead = 0;
	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			if (map[y][x] == '1') {
				if (chk[y][x] == 0) undead++;
				if (chk[y][x] > max) max = chk[y][x];
			}
		}
	}
	cout << max << "\n" << undead;
}

void solve()
{
	bfs();
}


int main()
{
	input();
	solve();
	return 0;
}