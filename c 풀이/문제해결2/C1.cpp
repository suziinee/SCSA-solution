#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n, l;
vector<int> gun;
struct AXIS { int x; int y; };
vector<AXIS> animal;
int ans;


void input()
{
	cin >> m >> n >> l;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		gun.push_back(a);
	}
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		animal.push_back({ x, y });
	}
}


void output()
{
	cout << ans;
}


bool compare(const AXIS& a1, const AXIS& a2) //(0, 0)에서 멀어지는 방향으로 정렬
{
	return (a1.x + a1.y) < (a2.x + a2.y);
}


void solve()
{
	sort(gun.begin(), gun.end());
	sort(animal.begin(), animal.end(), compare);

	int an = 0; int g = 0;
	for (g = 0; g < m;) {
		while ((an < n) && (abs(gun[g] - animal[an].x) + animal[an].y <= l)) {
			an++;
			ans++;
		}
		if (an == n) break;
		 
		//g 사대에서 an 동물을 못잡음
		if (gun[g] < animal[an].x) { //사대 포기
			g++;
		}
		else { //동물 포기
			an++;
		}
	}
}


int main()
{
	input();
	solve();
	output();
	return 0;
}