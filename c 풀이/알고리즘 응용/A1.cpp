#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int N, st, en;
vector<int> nums;


void input()
{
	cin >> N;
	int n;
	for (int i = 0; i < N; i++) {
		cin >> n;
		nums.push_back(n);
	}
}

void solve()
{
	st = 0; en = N - 1;
	int diff = abs(nums[st] + nums[en]);
	int min_st = st; int min_en = en; //st, en 저장용

	while (st < en) {
		//st, en-- 상태와 st++, en 상태 비교하기
		if (en - st >= 2) {
			int status_1 = abs(nums[en - 1] + nums[st]);
			int status_2 = abs(nums[en] + nums[st + 1]);
			if (status_1 < status_2) {
				if (diff > status_1) {
					diff = status_1;
					min_st = st; min_en = en - 1;
				}
				en--;
			}
			else {
				if (diff > status_2) {
					diff = status_2;
					min_st = st + 1; min_en = en;
				}
				st++;
			}
		}
		else { //en-st=1
			if (diff > abs(nums[st] + nums[en])) {
				diff = abs(nums[st] + nums[en]);
				min_st = st; min_en = en;
			}
			break;
		}
	}

	cout << nums[min_st] << " " << nums[min_en];
}


int main()
{
	input();
	solve();
	return 0;
}