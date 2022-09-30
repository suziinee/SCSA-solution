#include <iostream>
#include <vector>
using namespace std;

int N;
int min_f = 0x7fffffff; long long int sum_f;
struct TOWN { int n; int fish; };
vector<TOWN> town;


void input()
{
	cin >> N;
	int n, fish;
	for (int i = 0; i < N; i++) {
		cin >> n >> fish;
		town.push_back({ n, fish });
		if (fish < min_f) min_f = fish;
		sum_f += fish;
	}
}

bool check(long long int mid)
{
	long long int car = 0; //남는 것을 넘겨줌
	for (int i = 0; i < N - 1; i++) {
		if (town[i].fish + car >= mid) { //안받아도됨
			car = (town[i].fish + car - mid) - (town[i + 1].n - town[i].n);
			if (car < 0) car = 0;
		}
		else { //받아야함
			car = mid - (town[i].fish + car) + (town[i + 1].n - town[i].n);
			car *= -1;
		}
	}

	if (town[N - 1].fish + car >= mid) return true;
	else return false;
}

void solve()
{
	long long int ans; long long int mid;
	long long int st = min_f; 
	long long int en = sum_f / N;
	while (st <= en) {
		mid = (st + en) / 2;
		if (check(mid)) {
			ans = mid;
			st = mid + 1;
		}
		else {
			en = mid - 1;
		}
	}
	cout << ans;
}


int main()
{
	input();
	solve();
	return 0;
}