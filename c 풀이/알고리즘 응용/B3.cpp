#include <iostream>
#include <vector>
#include <string>
using namespace std;

string st; //유효한 알파벳만 모아놓음
string ans;
vector<int> xloc;
bool chk[13] = { false }; //1~12까지 사용


inline int key(char& c) { return c - 'A' + 1; }

void input()
{
	string input;
	int idx = 0;
	for (int i = 0; i < 5; i++) {
		cin >> input;
		for (int j = 0; j < 9; j++) {
			if (input[j] != '.') {
				st += input[j];
				if (input[j] == 'x') xloc.push_back(idx);
				else chk[key(input[j])] = true;
				idx++;
			}
		}
	}
}

bool complete(string& s)
{
	if (key(s[1]) + key(s[5]) + key(s[8]) + key(s[11]) != 26) return false;
	if (key(s[0]) + key(s[2]) + key(s[5]) + key(s[7]) != 26) return false;
	if (key(s[0]) + key(s[3]) + key(s[6]) + key(s[10]) != 26) return false;
	if (key(s[4]) + key(s[6]) + key(s[9]) + key(s[11]) != 26) return false;
	if (key(s[1]) + key(s[2]) + key(s[3]) + key(s[4]) != 26) return false;
	if (key(s[7]) + key(s[8]) + key(s[9]) + key(s[10]) != 26) return false;

	return true;
}

bool check(int& idx, string& s) //idx까지 완성이 된 상태
{
	switch (idx) {
	case 0: case 1: return true;
	case 2: {
		if (key(s[0]) + key(s[2]) >= 26) return false;
		if (key(s[1]) + key(s[2]) >= 26) return false;
		return true;
	}
	case 3: {
		if (key(s[0]) + key(s[3]) >= 26) return false;
		if (key(s[1]) + key(s[2]) + key(s[3]) >= 26) return false;
		return true;
	}
	case 4: {
		if (key(s[1]) + key(s[2]) + key(s[3]) + key(s[4]) != 26) return false;
		return true;
	}
	case 5: {
		if (key(s[0]) + key(s[2]) + key(s[5]) >= 26) return false;
		if (key(s[1]) + key(s[5]) >= 26) return false;
		return true;
	}
	case 6: {
		if (key(s[0]) + key(s[3]) + key(s[6]) >= 26) return false;
		if (key(s[4]) + key(s[6]) >= 26) return false;
		return true;
	}
	case 7: {
		if (key(s[0]) + key(s[2]) + key(s[5]) + key(s[7]) != 26) return false;
		return true;
	}
	case 8: {
		if (key(s[1]) + key(s[5]) + key(s[8]) >= 26) return false;
		if (key(s[7]) + key(s[8]) >= 26) return false;
		return true;
	}
	case 9: {
		if (key(s[4]) + key(s[6]) + key(s[9]) >= 26) return false;
		if (key(s[7]) + key(s[8]) + key(s[9]) >= 26) return false;
		return true;
	}
	case 10: {
		if (key(s[0]) + key(s[3]) + key(s[6]) + key(s[10]) != 26) return false;
		if (key(s[7]) + key(s[8]) + key(s[9]) + key(s[10]) != 26) return false;
		return true;
	}
	case 11: {
		if (key(s[1]) + key(s[5]) + key(s[8]) + key(s[11]) != 26) return false;
		if (key(s[4]) + key(s[6]) + key(s[9]) + key(s[11]) != 26) return false;
		return true;
	}
	}
}

bool dfs(string str, int s)
{
	if (s == (int)xloc.size()) { //도달하면 완성된 것?..
		if (complete(str)) {
			ans = str;
			return true;
		}
		return false;
	}

	for (int i = s; i < (int)xloc.size(); i++) {
		for (char c = 'A'; c <= 'L'; c++) {
			if (chk[key(c)]) continue;
			chk[key(c)] = true;
			str[xloc[i]] = c;

			if (check(xloc[i], str)) { //더 진행해도 되는지
				if (dfs(str, i + 1)) return true;
			}
			chk[key(c)] = false;
			str[xloc[i]] = 'x';
		}
	}
	return false;
}

void solve()
{
	int idx = 0;
	if (dfs(st, 0)) {
		for (int y = 0; y < 5; y++) {
			for (int x = 0; x < 9; x++) {
				switch (y * 9 + x) {
				case 4: 
				case 10: case 12: case 14: case 16: 
				case 20: case 24: 
				case 28: case 30: case 32: case 34: 
				case 40: {cout << ans[idx++]; break; }
				default: cout << '.';
				}
			}
			cout << "\n";
		}
	}
	
}


int main()
{
	input();
	solve();
	return 0;
}