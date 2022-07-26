#include <stdio.h>

int* func(int n, int nums[])
{
	for (int i = 2; i*i <= n; i++) {
		if (nums[i]) {
			int j = 2;
			while (i*j <= n) {
				nums[i*j] = 0;
				j += 1; 
			}
		}
	}
	return nums;
}

void main(void)
{
	int a, b; int min, max;
	scanf("%d %d", &a, &b);
	if ((a <= 0) || (b <= 0)) printf("Error!!");
	else {
		if (a > b) {
			min = b; max = a;
		}
		else {
			min = a; max = b;
		}

		int arr[10000] = { 0 }; int arr2[10000] = { 0 };
		for (int i = 1; i <= min; i++) arr[i] = i;
		for (int j = 1; j <= max; j++) arr2[j] = j;
		int* res = func(min, arr);
		int* res2 = func(max, arr2);

		printf("%d\n", 1);

		for (int i = 2; i <= max; i++) {
			if (res[i] != res2[i]) printf("%d\n", res2[i]);
		}
	}
}