#include <iostream>
#include <set>
#include <queue>
#include <string>
using namespace std;

set<string> chk;
int ans = 0x7fffffff;
string complete = "123456780";

struct AXIS { int y; int x; string key; int cnt; };
AXIS init_blk;
queue<AXIS> q;


void input()
{
	int n;
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			cin >> n;
			if (n == 0) {
				init_blk.x = x;
				init_blk.y = y;
			}
			init_blk.key += to_string(n);
		}
	}
	init_blk.cnt = 0;
}


int bfs()
{
	static int dx[] = { 0, 1, 0, -1 };
	static int dy[] = { -1, 0, 1, 0 };

	q.push(init_blk);
	chk.insert(init_blk.key);

	while (!q.empty()) {
		AXIS cur = q.front(); q.pop();

		for (int d = 0; d < 4; d++) { //ny, nx가 blk 후보
			AXIS next;
			next.x = cur.x + dx[d];
			next.y = cur.y + dy[d];
			next.key = cur.key;
			next.cnt = cur.cnt + 1;
			if (next.x < 0 || next.y < 0 || next.x >= 3 || next.y >= 3) continue;
			
			char tmp = cur.key[next.y * 3 + next.x]; //옮길 문자
			next.key[next.y * 3 + next.x] = '0';
			next.key[cur.y * 3 + cur.x] = tmp;
			
			auto it = chk.find(next.key);
			if (it != chk.end()) continue;
			if (next.key == complete) return next.cnt;
			chk.insert(next.key);
			q.push(next);
		}
	}
	return -1;
}


void solve()
{
	cout << bfs();
}


int main()
{
	input();
	solve();
	return 0;
}