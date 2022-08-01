#include <stdio.h>

int n;
int arr[100000];

int LIS(void)
{
	int cnt = 1; int max = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i - 1] <= arr[i]) cnt += 1;
		else {
			max = (max > cnt) ? max : cnt;
			cnt = 1;
		}
	}
	max = (max > cnt) ? max : cnt;
	return max;
}

int rev_LIS(void)
{
	int cnt = 1; int max = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i - 1] >= arr[i]) cnt += 1;
		else {
			max = (max > cnt) ? max : cnt;
			cnt = 1;
		}
	}
	max = (max > cnt) ? max : cnt;
	return max;
}

void main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	int lis = LIS();
	int rev_lis = rev_LIS();
	printf("%d", lis > rev_lis ? lis : rev_lis);
}