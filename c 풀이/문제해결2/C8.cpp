#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

#define MAXT 100000
int m, t, n; 
struct P { int t; int idx; int ans; };
queue<P> q[2]; //0은 left, 1은 right
vector<P> sol;


void input()
{
	cin >> m >> t >> n;
	for (int i = 0; i < n; i++) {
		int a; string s;
		cin >> a >> s;
		if (s == "left") {
			q[0].push({ a, i, 0 });
		}
		else {
			q[1].push({ a, i, 0 });
		}
	}
}

bool compare(const P& p1, const P& p2)
{
	return p1.idx < p2.idx;
}

void output()
{
	//sol에 있는것들을 idx 순으로 정렬
	sort(sol.begin(), sol.end(), compare);
	for (int i = 0; i < n; i++) {
		cout << sol[i].ans << "\n";
	}
}


void solve()
{
	int Time = 0;
	queue<P> boat; //배에 태운 사람
	int dir = 0; //배는 처음에 왼쪽

	while (sol.size() < n) {

		//현재 보트 방향의 사람을 태움
		while (boat.size() < m && !q[dir].empty() && q[dir].front().t <= Time) {
			boat.push(q[dir].front());
			q[dir].pop();
		}
		//만약에 못태웠다면 여기서 더 기다릴지 아닐지 판단
		if (boat.size() == 0) {
			//dir front와 반대 front 비교
			//이때 비어있는 경우도 생각해야함 -> 비어있다면 최대값 주기
			int here, there;
			if (q[dir].empty()) here = MAXT + 100;
			else here = q[dir].front().t;
			if (q[(dir + 1) % 2].empty()) there = MAXT + 100;
			else there = q[(dir + 1) % 2].front().t;

			if (there >= here) { //여기서 더 기다리기
				Time += here - Time;
				continue;
			}
			else { //반대편으로 가야함
				if (there > Time) { //기다렸다가 가기
					Time += there - Time;
				}
			}
		}
		
		//반대편으로 이동 
		Time += t; dir = (dir + 1) % 2;
		//내려주기
		while (!boat.empty()) {
			boat.front().ans = Time;
			sol.push_back(boat.front());
			boat.pop();
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