#include <stdio.h>

int n;
long long int arr[1000 + 10];
long long int X[1000 + 10];
int ans;

int in_X(int num, int idx)
{
	for (int i = 0; i < idx; i++) {
		if (X[i] == num) return 1;
	}
	return 0;
}

void input(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (in_X(arr[i], i) == 0) {
			X[i] = arr[i];
			ans += 1;
		}
	}
}

void main(void)
{
	input();
	printf("%d", ans);
}