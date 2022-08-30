#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
struct TIME {
	int start; int end;
};
vector<TIME> arr;
int stay;
int emp;

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		TIME t;
		cin >> t.start >> t.end;
		arr.push_back(t);
	}
}

void output()
{
	cout << stay << " " << emp;
}

bool compare(const TIME& t1, const TIME& t2)
{
	if (t1.start == t2.start) {
		return t1.end < t2.end;
	}
	else {
		return t1.start < t2.start;
	}
}

void solve()
{
	sort(arr.begin(), arr.end(), compare);

	TIME tmp = arr[0]; //stay를 위한 객체
	
	for (int i = 0; i < n; i++) {
		if (tmp.end >= arr[i].start) { //tmp가 포함 가능
			stay = max({ stay, abs(arr[i].end - tmp.start)});
			tmp.end = tmp.start + stay;
		}
		else { //tmp가 포함 불가 -> 새로운 tmp 갱신 필요
			emp = max({ emp, arr[i].start - tmp.end });
			tmp = arr[i];
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