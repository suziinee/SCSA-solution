#include <stdio.h>

int n;
int arr[50 + 10];
int max_idx;

int func(void)
{
	for (int i = 0; i < n; i++) {
		if (arr[i] > arr[max_idx]) {
			max_idx = i; 
		}
	}

	int max_cnt = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == arr[max_idx]) max_cnt++;
	}
	return max_cnt;
}

void main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	int f = func();
	if (f == n) {
		if (arr[max_idx] == 0) printf("%d", arr[max_idx]);
		else if (arr[max_idx] == (n - 1)) printf("%d", n);
	}
	else {
		printf("%d", arr[max_idx]);
	}
}