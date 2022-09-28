#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

#define MAXM 300000
int M, N, Q;
int comp[MAXM + 1]; //index가 컴퓨터 번호, value가 자리에 앉은 학생 번호
unordered_map<int, int> ht; //<학생 번호, 컴퓨터 번호>

vector<int> f_nums; //출력해야할 학생 번호 저장
vector<int> init; //pq를 만들기 위해 컴퓨터 번호 저장, 가장 처음에 0 가장 마지막에 M+1 삽입되어있음

struct INTERVAL {
	int s;
	int e;
	bool operator<(const INTERVAL& i) const {
		if ((e - s) == (i.e - i.s)) return s > i.s;
		return (e - s) < (i.e - i.s);
	}
};
priority_queue<INTERVAL> pq;


void make_pq()
{
	int tmp = init[0];
	for (int i = 1; i < N + 2; i++) {
		pq.push({ tmp, init[i] });
		tmp = init[i];
	}
}

void input()
{
	cin >> M >> N >> Q;
	int n;

	init.push_back(0);
	for (int i = 1; i <= N; i++) { //i가 학생 번호
		cin >> n;
		init.push_back(n);
		comp[n] = i;
		ht.insert({ i, n });
	}
	init.push_back(M + 1);

	for (int i = 0; i < Q; i++) {
		cin >> n;
		f_nums.push_back(n);
	}

	make_pq();
}

void solve()
{
	//N+1번부터 M번 학생을 컴퓨터에 배치하기
	for (int i = N + 1; i <= M; i++) {
		INTERVAL cur = pq.top(); pq.pop();
		int seat = (cur.s + cur.e) / 2;
		comp[seat] = i;
		ht.insert({ i, seat });
		//pq에 삽입해주기..
		pq.push({ cur.s, seat });
		pq.push({ seat, cur.e });
	}

	//출력
	for (int n : f_nums) cout << ht[n] << "\n";
}


int main()
{
	input();
	solve();
	return 0;
}