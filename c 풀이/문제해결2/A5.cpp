#include <iostream>
#include <vector>
using namespace std;

int n, t, m;
int ans;
struct AXIS {
	int y; int x;
};
vector<AXIS> fish;

void input()
{
	cin >> n >> t >> m;
	for (int i = 0; i < m; i++) {
		AXIS a;
		cin >> a.y >> a.x;
		fish.push_back(a);
	}
}

void output()
{
	cout << ans;
}

int net(const AXIS& a, const AXIS& b, const AXIS& c, const AXIS& d)
{
	//범위체크
	if (a.x<1 || a.y<1 || a.x>n || a.y>n) return 0;
	if (b.x<1 || b.y<1 || b.x>n || b.y>n) return 0;
	if (c.x<1 || c.y<1 || c.x>n || c.y>n) return 0;
	if (d.x<1 || d.y<1 || d.x>n || d.y>n) return 0;

	//안에 물고기가 몇마리 있는지
	int sum = 0;
	for (int f = 0; f < m; f++) {
		if (fish[f].x >= a.x && fish[f].x <= c.x && fish[f].y >= a.y && fish[f].y <= c.y) {
			sum += 1;
		}
	}
	return sum;
}


const int dx[] = { 0, 0, 1, 0, -1 };
const int dy[] = { 0, -1, 0, 1, 0 };
void check(int* res)
{
	int a = res[0]; int b = res[1];

	for (int i = 0; i < m; i++) {

		for (int dir = 0; dir < 5; dir++) {
			int nx = fish[i].x + dx[dir];
			int ny = fish[i].y + dy[dir];

			int sum;
			AXIS n1; AXIS n2; AXIS n3; AXIS n4;

			n1 = { ny, nx }; n2 = { ny, nx + b };
			n3 = { ny + a, nx + b }; n4 = { ny + a, nx };
			sum = net(n1, n2, n3, n4);
			if (sum > ans) ans = sum;

			n1 = { ny - a, nx }; n2 = { ny - a, nx + b };
			n3 = { ny, nx + b }; n4 = { ny, nx };
			sum = net(n1, n2, n3, n4);
			if (sum > ans) ans = sum;

			n1 = { ny - a, nx - b }; n2 = { ny - a, nx };
			n3 = { ny, nx }; n4 = { ny, nx - b };
			sum = net(n1, n2, n3, n4);
			if (sum > ans) ans = sum;

			n1 = { ny, nx - b }; n2 = { ny, nx };
			n3 = { ny + a, nx }; n4 = { ny + a, nx - b };
			sum = net(n1, n2, n3, n4);
			if (sum > ans) ans = sum;
		}
	}
}


void solve()
{
	int res[2];
	for (int i = 1; i < (t / 2); i++) {
		res[0] = i;
		res[1] = (t / 2) - i;
		check(res);
	}
}


int main()
{
	input();
	solve();
	output();
	return 0;
}
