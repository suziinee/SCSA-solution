#include <stdio.h>

int a[20];

void sort()
{
	int tmp;
	for (int i = 0; i < 20; i++) {
		for (int j = i + 1; j < 20; j++) {
			if (a[i] > a[j]) {
				tmp = a[j];
				a[j] = a[i];
				a[i] = tmp;
			}
		}
	}
}

void main(void)
{
	for (int i = 0; i < 20; i++) {
		scanf("%d", &a[i]);
	}

	sort();
	
	for (int i = 0; i < 20; i++) {
		printf("%d ", a[i]);
	}
}