#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int N, M;
struct PERSON { int score; int num; };
unordered_map<string, PERSON> ht;


void input()
{
	cin >> N;
	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		ht.insert({ s, { 0, i } });
	}
	cin >> M;
	int score;
	for (int i = 0; i < M; i++) {
		cin >> s >> score;
		auto iter = ht.find(s);
		if (iter != ht.end()) (iter->second.score) += score;
	}
}

bool compare(const pair<string, PERSON>& p1, const pair<string, PERSON>& p2) {
	if (p1.second.score == p2.second.score) return p1.second.num < p2.second.num;
	return p1.second.score > p2.second.score;
}

void solve()
{
	vector<pair<string, PERSON>> vec(ht.begin(), ht.end());
	sort(vec.begin(), vec.end(), compare);

	for (int i = 0; i < 3; i++) {
		cout << vec[i].first << " " << vec[i].second.score << "\n";
	}
}


int main(void)
{
	input();
	solve();
	return 0;
}