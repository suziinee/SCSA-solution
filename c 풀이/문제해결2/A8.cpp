#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int n;
struct TEMP {
	int x; int y;
};
struct REFRI {
	int min; int max;
};
vector<TEMP> temp;
stack<REFRI> refri;

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		TEMP t;
		cin >> t.x >> t.y;
		temp.push_back(t);
	}
}

void output()
{
	cout << refri.size();
}

bool compare(const TEMP& t1, const TEMP& t2)
{
	return t1.x < t2.x;
}

void solve()
{
	sort(temp.begin(), temp.end(), compare);

	REFRI r;
	r.min = temp[0].x; r.max = temp[0].y;
	refri.push(r); 

	for (int i = 1; i < n; i++) { //temp
		if (refri.top().max >= temp[i].x) { //넣을 수 있음
			refri.top().min = temp[i].x;
			refri.top().max = min(refri.top().max, temp[i].y);
		}
		else {
			REFRI r;
			r.min = temp[i].x; r.max = temp[i].y;
			refri.push(r);
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
