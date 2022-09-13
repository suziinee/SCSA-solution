#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int T;
string map[5];
int pins; 
int ans;

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { -1, 0, 1, 0 };


void dfs(int p) //움직일 수 있는 핀을 찾으면 움직이기
{
	if (ans > p) ans = p; //ans는 남은 핀의 개수

	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 9; x++) {
			if (map[y][x] == 'o') {
				for (int d = 0; d < 4; d++) {
					int nx = x + dx[d]; int nnx = nx + dx[d];
					int ny = y + dy[d]; int nny = ny + dy[d];

					if (nx < 0 || ny < 0 || nx >= 9 || ny >= 5) continue;
					if (nnx < 0 || nny < 0 || nnx >= 9 || nny >= 5) continue;

					if (map[ny][nx] == 'o' && map[nny][nnx] == '.') {
						map[y][x] = '.';
						map[ny][nx] = '.';
						map[nny][nnx] = 'o';

						dfs(p - 1);

						map[y][x] = 'o';
						map[ny][nx] = 'o';
						map[nny][nnx] = '.';
					}
				}
			}
		}
	}
}

void input()
{
	cin >> T;
	for (int t = 0; t < T; t++) {
		//초기화
		pins = 0;

		for (int i = 0; i < 5; i++) {
			cin >> map[i];
			for (int j = 0; j < 9; j++) {
				if (map[i][j] == 'o') pins++;
			}
		}

		ans = pins;
		dfs(pins);
		cout << ans << " " << pins - ans << "\n";
	}
}


int main(void)
{
	input();
	return 0;
}