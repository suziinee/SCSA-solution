#include <iostream>
#include <list>
#include <string>
using namespace std;

int N;
list<char> lst;

void input()
{
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) lst.push_back(str[i]);

	auto p = lst.end();
	cin >> N;
	for (int i = 0; i < N; i++) {
		char order, in;
		cin >> order;
		if (order == 'L') {
			if (p != lst.begin()) p--;
		}
		else if (order == 'D') {
			if (p != lst.end()) p++;
		}
		else if (order == 'B') {
			if (p != lst.begin()) lst.erase(prev(p));
		}
		else if (order == 'P') {
			cin >> in;
			lst.insert(p, in);
		}
	}

	for (char c : lst) cout << c;
}


int main()
{
	input();
	return 0;
}