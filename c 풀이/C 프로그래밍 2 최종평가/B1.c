#include <stdio.h>

int arr[9 + 3];
int max_idx = 0;

void main(void)
{
	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < 9; i++) {
		if (arr[i] > arr[max_idx]) max_idx = i;
	}
	printf("%d\n%d", arr[max_idx], max_idx+1);
}