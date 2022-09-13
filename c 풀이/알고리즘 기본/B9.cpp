#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
using namespace std;

#define MAXN 1000
int N, K;
vector<string> bit = { "0" };
list<int> arr[MAXN + 10];
int st, en;

queue<int> q;
bool chk[MAXN + 10]; 
int path[MAXN + 10];


void input()
{
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		bit.push_back(s);
	}

	cin >> st >> en;
}

int bit_calcul(const string& s1, const string& s2)
{
	int ret = 0;
	for (int i = 0; i < K; i++) {
		if (s1[i] != s2[i]) ret++;
	}
	return ret;
}

void make_haming()
{
	for (int i = 1; i <= N; i++) {
		string me = bit[i];
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			if (bit_calcul(me, bit[j]) == 1) arr[i].push_back(j);
		}
	}
}

int bfs()
{
	q.push(st);
	chk[st] = true;
	path[st] = -1; //시작

	while (!q.empty()) {
		int n = q.front(); q.pop();

		for (int nn : arr[n]) {
			if (chk[nn] == false) { //처음 방문할 경우
				chk[nn] = true;
				path[nn] = n;
				q.push(nn);
				if (nn == en) return 1;
			}
		}
	}

	return -1;
}

void print_route(int num)
{
	if (num == -1) return;
	print_route(path[num]);
	cout << num << " ";
}

void solve()
{
	make_haming();
	int ans = bfs();

	if (ans == -1) cout << -1;
	else print_route(en);
}


int main(void)
{
	input();
	solve();
	return 0;
}