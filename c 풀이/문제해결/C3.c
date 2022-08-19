#include <stdio.h>

int n;
double arr[10000 + 1];
double d[10000 + 1]; //해당 요소까지 최대 곱
double ans;

void input(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &arr[i]);
	}
	
	//d 배열 init
	for (int i = 0; i < n; i++) {
		d[i] = arr[i];
	}
}

void solve(void)
{
	for (int i = 1; i < n; i++) {
		d[i] = (d[i] > (d[i - 1] * arr[i])) ? d[i] : (d[i - 1] * arr[i]);
	}

	double max = -1;
	for (int i = 0; i < n; i++) {
		if (d[i] > max) max = d[i];
	}
	ans = max;
}


void main(void)
{
	input();
	solve();
	printf("%.3f", ans);
}