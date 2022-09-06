#include <iostream>
#include <cstring>
#include <list>
#include <vector>
#include <queue>
using namespace std;

#define MAXN 500
int n;
list<int> adjlist[MAXN + 1];
struct PAGE { int n; int click; };
int max_node;


void input()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		adjlist[a].push_back(b);
		max_node = max(a, max_node);
		max_node = max(b, max_node);
	}
}

int bfs(int s)
{
	queue<PAGE> q;
	int chk[MAXN + 1];
	memset(chk, 0xff, sizeof(chk));

	q.push({ s, 0 });
	chk[s] = 0;

	while (!q.empty()) {
		PAGE data = q.front(); q.pop();

		for (auto a : adjlist[data.n]) {
			if (chk[a] == -1) {
				q.push({ a, data.click + 1 });
				chk[a] = data.click + 1;
			}
		}
	}

	int sum = 0;
	for (int i = 1; i <= max_node; i++) {
		sum += chk[i];
	}
	return sum;
}

double solve()
{
	int ans = 0;

	for (int i = 1; i <= max_node; i++) {
		ans += bfs(i);
	}

	return (double) ans / (max_node * (max_node - 1));
}

void output(const double& ans)
{
	cout << fixed;
	cout.precision(3);
	cout << ans;
}


int main(void) 
{
	input();
	double ans = solve();
	output(ans);
	return 0;
}