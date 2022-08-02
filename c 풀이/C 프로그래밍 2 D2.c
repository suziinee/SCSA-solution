#include <stdio.h>

int N;
int arr[100000];

int LIS(void)
{
	int up = 1; int down = 1;
	int max = 1;

	for (int i = 0; i < N-1; i++) {
		if (arr[i] <= arr[i + 1]) up += 1;
		else { 
			max = max > up ? max : up;
			up = 1;
		}

		if (arr[i] >= arr[i + 1]) down += 1;
		else { 
			max = max > down ? max : down;
			down = 1;
		}
	}
	max = max > down ? max : down;
	max = max > up ? max : up;
	return max;
}

void main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	int lis = LIS();
	printf("%d", lis);
}