#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int T, N, M;
struct CAR {
	int prime_cost;
	int pickup_cost;
	int plus;
};
unordered_map<string, CAR> cars;

struct EVENT {
	bool consis = true;
	string name;
	string car = "none";
	int p_time = 0; int r_time = 0; int a_time = 0;
	int d = 0;
	int a = 0;
	int sum_cost = 0;

	bool operator<(const EVENT& e) const {
		return name < e.name;
	}
};
EVENT even[500]; int idx = 0;
unordered_map<string, EVENT*> ht;


void car_input()
{
	string n;
	int p, q, k;

	for (int i = 0; i < N; i++) {
		cin >> n >> p >> q >> k;
		cars.insert({ n, {p, q, k} });
	}
}


void event_input()
{
	int t; string name;
	char p; string car; int d; int s;

	for (int i = 0; i < M; i++) {
		cin >> t >> name >> p;
		auto iter = ht.find(name);

		if (iter == ht.end()) { //ht에 없음

			if (p == 'p') {
				cin >> car;
				even[idx].name = name;
				even[idx].p_time = t;
				even[idx].car = car;
				ht.insert({ name, &even[idx] });
				idx++;
			}
			else if (p == 'r') {
				cin >> d;
				even[idx].name = name;
				even[idx].r_time = t;
				even[idx].d = d;
				ht.insert({ name, &even[idx] });
				idx++;
			}
			else if (p == 'a') {
				cin >> s;
				even[idx].name = name;
				even[idx].a_time = t;
				even[idx].a = s;
				ht.insert({ name, &even[idx] });
				idx++;
			}
		}
		else { //ht에 있음
			EVENT* e = iter->second;

			if (p == 'p') {
				cin >> car;
				if (!e->consis) continue;
				if (e->r_time >= t) { e->consis = false; continue; }
				
				e->p_time = t;
				e->car = car;
			}
			else if (p == 'r') {
				cin >> d;
				if (!e->consis) continue;
				if (e->p_time >= t || e->p_time == 0) { e->consis = false; continue; }
				if (e->car == "none") { e->consis = false; continue; }

				auto car_iter = cars.find(e->car);
				if (car_iter == cars.end()) { e->consis = false; continue; }

				//이전 차 대여비용 계산
				if (e->p_time < t) {
					e->sum_cost += car_iter->second.pickup_cost;
					e->sum_cost += d * car_iter->second.plus;
				}
				//이전 차 사고비용 계산
				if (e->a_time >= e->p_time && e->a_time <= t) {
					e->sum_cost += ceil(car_iter->second.prime_cost * e->a * 0.01);
				}

				//초기화
				e->p_time = 0;
				e->r_time = 0;
				e->a_time = 0;
				e->car = "none";
				e->d = 0; e->a = 0;
			}
			else if (p == 'a') {
				cin >> s;
				if (!e->consis) continue;
				if (e->p_time && e->r_time) {
					if (e->p_time > t || e->r_time < t) { e->consis = false; continue; }
				}

				e->a_time = t;
				e->a = s;
			}
		}
	}
}


void solve()
{	
	sort(even, even + idx);
	
	//cout << "\n\n";

	for (int i = 0; i < idx; i++) {
		if (even[i].consis && even[i].sum_cost > 0) {
			cout << even[i].name << " " << even[i].sum_cost << "\n";
		}
		else {
			cout << even[i].name << " INCONSISTENT\n";
		}
	}
}


void input()
{
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> M;

		cars.clear();
		ht.clear();

		car_input();
		event_input();
		solve();
	}
}


int main()
{
	input();
	return 0;
}