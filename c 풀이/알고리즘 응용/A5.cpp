#include <iostream>
#include <vector>
using namespace std;

vector<int> lut[32]; //1~31
vector<int> lut_score; //1~31
int dice[10];
int ans = -1;

struct MARKER { int loc; int score; };
vector<MARKER> marker;


void init_lut()
{
	for (int i = 0; i <= 15; i++) {
		if (i != 5 && i != 10 && i != 15) {
			lut[i] = { 0, i + 1, i + 2, i + 3, i + 4, i + 5 };
		}
	}

	lut[5] = { 0, 21, 22, 23, 24, 25 };
	lut[10] = { 0, 27, 28, 24, 25, 26 };
	lut[15] = { 0, 29, 30, 31, 24, 25 };
	lut[16] = { 0, 17, 18, 19, 20, 32 };
	lut[17] = { 0, 18, 19, 20, 32, 32 };
	lut[18] = { 0, 19, 20, 32, 32, 32 };
	lut[19] = { 0, 20, 32, 32, 32, 32 };
	lut[20] = { 0, 32, 32, 32, 32, 32 };
	lut[21] = { 0, 22, 23, 24, 25, 26 };
	lut[22] = { 0, 23, 24, 25, 26, 20 };
	lut[23] = { 0, 24, 25, 26, 20, 32 };
	lut[24] = { 0, 25, 26, 20, 32, 32 };
	lut[25] = { 0, 26, 20, 32, 32, 32 };
	lut[26] = { 0, 20, 32, 32, 32, 32 };
	lut[27] = { 0, 28, 24, 25, 26, 20 };
	lut[28] = { 0, 24, 25, 26, 20, 32 };
	lut[29] = { 0, 30, 31, 24, 25, 26 };
	lut[30] = { 0, 31, 24, 25, 26, 20 };
	lut[31] = { 0, 24, 25, 26, 20, 32 };
	
	lut_score = { 0, 2, 4, 6, 8, 10, 12, 14, 16,
				18, 20, 22, 24, 26, 28, 30, 32,
				34, 36, 38, 40, 13, 16, 19, 25,
				30, 35, 22, 24, 28, 27, 26, 0};
}

void input()
{
	for (int i = 0; i < 10; i++) {
		cin >> dice[i];
	}
	init_lut();
}

bool check(int& after, int& idx) //idx에서 이동하려는 after의 위치가 marker에 있는지 확인
{
	for (int i = 0; i < 4; i++) {
		if (i == idx) continue;
		if (after != 32 && marker[i].loc == after) return false;
	}
	return true;
}

void dfs(int n)
{
	if (n == 10) {
		int sum = 0;
		for (MARKER m : marker) sum += m.score;
		if (ans < sum) ans = sum;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (marker[i].loc == 32) continue;

		int before = marker[i].loc;
		int after = lut[marker[i].loc][dice[n]]; //**
		int score = lut_score[after];
		if (check(after, i) == false) continue;
		else {
			marker[i].loc = after;
			marker[i].score += score;
			dfs(n + 1);
			marker[i].loc = before;
			marker[i].score -= score;
		}
	}
}

void solve()
{
	marker.push_back({ 0, 0 });
	marker.push_back({ 0, 0 });
	marker.push_back({ 0, 0 });
	marker.push_back({ 0, 0 });

	dfs(0);
	cout << ans;
}


int main()
{
	input();
	solve();
	return 0;
}