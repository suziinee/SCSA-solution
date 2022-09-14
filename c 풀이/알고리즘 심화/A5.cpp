#include <iostream>
#include <string>
using namespace std;

#define MAXN 100
int N;
string map1[MAXN];
string map2[MAXN];

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { -1, 0, 1, 0 };


void input()
{
	cin >> N;
	for (int i = 0; i < N; i++) { 
		cin >> map1[i]; 
		map2[i] = map1[i];
	}
}

void dfs_B(int y, int x) //map1, 2
{
	map1[y][x] = 'Z';
	map2[y][x] = 'Z';

	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (map1[ny][nx] == 'B') { dfs_B(ny, nx); }
	}
}

void dfs_R(int y, int x) //map1
{
	map1[y][x] = 'Z';

	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (map1[ny][nx] == 'R') { dfs_R(ny, nx); }
	}
}

void dfs_G(int y, int x) //map1
{
	map1[y][x] = 'Z';

	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (map1[ny][nx] == 'G') { dfs_G(ny, nx); }
	}
}

void dfs_RG(int y, int x) //map2
{
	map2[y][x] = 'Z';

	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (map2[ny][nx] == 'R' || map2[ny][nx] == 'G') { dfs_RG(ny, nx); }	
	}
}

void solve()
{
	int m = 0; int n = 0; //일반, 적록색맹

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map1[y][x] == 'B') { dfs_B(y, x); m++; n++; }
			if (map1[y][x] == 'R') { dfs_R(y, x); m++; }
			if (map1[y][x] == 'G') { dfs_G(y, x); m++; }
			if (map2[y][x] == 'R' || map2[y][x] == 'G') { dfs_RG(y, x); n++; }
		}
	}

	cout << m << " " << n;
}


int main(void)
{
	input();
	solve();
	return 0;
}