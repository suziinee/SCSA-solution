#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

set<string> join;
set<string> login;

int N;
struct ORDER { int n; string id; };
vector<ORDER> ord;


void input()
{
	cin >> N;
	int n; string id;
	for (int i = 0; i < N; i++) {
		cin >> n >> id;
		ord.push_back({ n, id });
	}
}


void solve()
{
	for (ORDER o : ord) {
		auto it_join = join.find(o.id);
		auto it_login = login.find(o.id);

		switch (o.n) {
		case 1: { //가입 유무 판단
			if (it_join != join.end()) cout << "1\n";
			else cout << "0\n";
			break;
		}
		case 2: { //로그인 유무 판단
			if (it_join != join.end() && it_login != login.end()) cout << "1\n";
			else cout << "0\n";
			break;
		}
		case 3: { //아이디 등록
			if (it_join == join.end() && it_login == login.end()) {
				join.insert(o.id);
			}
			cout << join.size() << "\n";
			break;
		}
		case 4: { //아이디 삭제
			if (it_join != join.end()) {
				join.erase(it_join);
				if (it_login != login.end()) login.erase(it_login);
			}
			cout << join.size() << "\n";
			break;
		}
		case 5: { //로그인
			if (it_join != join.end() && it_login == login.end()) {
				login.insert(o.id);
			}
			cout << login.size() << "\n";
			break;
		}
		case 6: { //로그아웃
			if (it_join != join.end() && it_login != login.end()) {
				login.erase(it_login);
			}
			cout << login.size() << "\n";
			break;
		}
		}
	}
}


int main()
{
	input();
	solve();
	return 0;
}