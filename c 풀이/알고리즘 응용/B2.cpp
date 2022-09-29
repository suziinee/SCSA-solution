#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAXN 10
int N;
char map[MAXN][MAXN];

struct AXIS { int y; int x; };
AXIS st;
queue<AXIS> q;
bool chk[MAXN][MAXN]; //물이 흐르는지 안흐르는지 체크


void input()
{
	cin >> N;
	cin >> st.x >> st.y;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}
}

void move(vector<int> dir, AXIS& cur, bool (*chk)[MAXN], queue<AXIS>& q)
{
	static int dx[] = { 0, 1, 0, -1 };
	static int dy[] = { -1, 0, 1, 0 };
	static char lut[4][7] = {{'2', '3', '4', '7', '8', '9', 'B'}, //0
							{'1', '4', '5', '8', '9', 'A', 'B'}, //1
							{'2', '5', '6', '7', '9', 'A', 'B'},  //2
							{'1', '3', '6', '7', '8', 'A', 'B'}}; //3

	for (int d : dir) {
		int nx = cur.x + dx[d];
		int ny = cur.y + dy[d];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		
		for (char c : lut[d]) {
			if (map[ny][nx] == c && chk[ny][nx] == false) {
				chk[ny][nx] = true;
				q.push({ ny, nx });
			}
		}
	}
}

void bfs()
{
	if (map[st.y][st.x] != '0') {
		q.push(st);
		chk[st.y][st.x] = true;
	}
	
	while (!q.empty()) {
		AXIS cur = q.front(); q.pop();

		switch (map[cur.y][cur.x]) { 
		case '1': {
			move({ 1, 3 }, cur, chk, q);
			break;
		}
		case '2': {
			move({ 0, 2 }, cur, chk, q);
			break;
		}
		case '3': {
			move({ 1, 2 }, cur, chk, q);
			break;
		}
		case '4': {
			move({ 2, 3 }, cur, chk, q);
			break;
		}
		case '5': {
			move({ 0, 3 }, cur, chk, q);
			break;
		}
		case '6': {
			move({ 0, 1 }, cur, chk, q);
			break;
		}
		case '7': {
			move({ 0, 1, 2 }, cur, chk, q);
			break;
		}
		case '8': {
			move({ 1, 2, 3 }, cur, chk, q);
			break;
		}
		case '9': {
			move({ 0, 2, 3 }, cur, chk, q);
			break;
		}
		case 'A': {
			move({ 0, 1, 3 }, cur, chk, q);
			break;
		}
		case 'B': {
			move({ 0, 1, 2, 3 }, cur, chk, q);
			break;
		}
		}
	}
}

void solve()
{
	bfs();

	int cnt = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x] != '0' && chk[y][x] == false) cnt++;
		}
	}
	cout << cnt;
}


int main()
{
	input();
	solve();
	return 0;
}