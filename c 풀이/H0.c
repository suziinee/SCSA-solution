#include <stdio.h>

int idx = 0;

int* func(int n, int nums[])
{
	while (n) {
		nums[idx] = n % 10;
		n /= 10; idx++;
	}
	return nums;
}

void main(void)
{
	int n;
	scanf("%d", &n);
	int nums[100] = { 0 };
	int* ans = func(n, nums);

	for (int i = 0; i < idx; i++) {
		printf("%d", ans[i]);
	}
}
		
    
    