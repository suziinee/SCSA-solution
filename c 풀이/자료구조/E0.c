#include <stdio.h>

int n;
int arr[5000 + 10];
int ans; 

void swap(int x, int y)
{
	int tmp = arr[x];
	arr[x] = arr[y];
	arr[y] = tmp;
}

int partition(int left, int right)
{
	int pivot = arr[left];
	int low = left; int high = right + 1;
	for (;;) {
		do {
			low++;
		} while (low <= right && arr[low] < pivot);
		do {
			high--;
		} while (high >= left && arr[high] > pivot);
		if (low < high) swap(low, high);
		else break;
	}
	swap(left, high);
	return high;
}

void quick_sort(int left, int right)
{
	if (left < right) {
		int q = partition(left, right);
		quick_sort(left, q - 1);
		quick_sort(q + 1, right);
	}
}

void insertion_sort(int start)
{
	int idx = 0; int tmp = arr[start];
	for (int i = start; i < n; i++) {
		if (tmp > arr[i]) {
			idx = i;
		}
	}
	if (idx == 0) return;
	for (int i = start + 1; i <= idx; i++) {
		arr[i - 1] = arr[i];
	}
	arr[idx] = tmp;
}

///////////////////////////////////

void func(void)
{
	if (n == 1) {
		ans += arr[0];
		return;
	}
	
	int i = 0;
	while (i < n - 1) { //0~n-2까지
		arr[i + 1] = arr[i] + arr[i + 1];
		ans += arr[i + 1]; 
		i++;
		insertion_sort(i);
	}
}

void main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	quick_sort(0, n - 1);
	func();
	printf("%d\n", ans);
}
