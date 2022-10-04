#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> mat;
int pick[12];
unordered_set<long long int> chk;


void dfs(int s, int n)
{
	if (n == M) {
		int new_pick[12];
		copy(pick, pick + 12, new_pick); //원래 pick이 훼손되면 안됨
		sort(new_pick, new_pick + M); //오름차순 정렬
		long long int tmp = 0;
		long long int mul = 100;
		for (int i = 0; i < M; i++) {
			tmp += ((long long int)new_pick[i] * mul);
			mul *= 100;
		}
		if (chk.find(tmp) == chk.end()) chk.insert(tmp);
		return;
	}

	for (int i = s; i < N; i++) {
		pick[n] = mat[i];
		dfs(i + 1, n + 1);
	}
}

void input()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M;

		mat.clear();
		chk.clear();
		fill(pick, pick + 12, 0);

		int n;
		for (int i = 0; i < N; i++) {
			cin >> n;
			mat.push_back(n);
		}
		
		dfs(0, 0);
		cout << chk.size() << "\n";
	}
}


int main()
{
	input();
	return 0;
}