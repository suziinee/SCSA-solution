#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n;
vector<int> arr;
stack<int> s;
long long int ans;

void input()
{
	cin >> n;
	int a; 
	for (int i = 0; i < n; i++) {
		cin >> a;
		arr.push_back(a);
	}
}

void output()
{
	cout << ans;
}


void solve()
{
	for (int i = 0; i < n; i++) {
		if (s.empty()) {
			s.push(arr[i]);
			continue;
		}
		
		if (arr[i] < s.top()) {
			ans += s.size();
			s.push(arr[i]);
		}
		else {
			while (true) {
				if (s.empty()) break;
				if (arr[i] >= s.top()) s.pop();
				else break;
			}
			ans += s.size();
			s.push(arr[i]);
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
