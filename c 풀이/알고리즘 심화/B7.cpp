#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

#define MAXN 10000
int N, M;

struct CAND {
	string name; 
	int idx;
	int score;
	bool operator<(CAND& c) {
		if (score == c.score) return idx < c.idx;
		return score > c.score;
	}
};
CAND cand[MAXN];
unordered_map<string, CAND*> ht;


void input()
{
	cin >> N;
	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		cand[i] = { s, i, 0 };
		ht.insert({ s, &cand[i]});
	}
}

void vote()
{
	cin >> M;
	string s; int n;
	for (int i = 0; i < M; i++) {
		cin >> s >> n;
		auto iter = ht.find(s);
		if (iter != ht.end()) {
			iter->second->score += n;
		}
	}
}

void solve()
{
	sort(cand, cand + N);
	for (int i = 0; i < 3; i++) {
		cout << cand[i].name << " " << cand[i].score << "\n";
	}
}


int main()
{
	input();
	vote();
	solve();
	return 0;
}