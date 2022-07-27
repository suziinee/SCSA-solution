#include <stdio.h>

void func(int k, int n)
{
	int time = 0;
	int bomb = k;
	int t; 
	char a='A';

	for (int i = 0; i < n; i++) {
		scanf(" %d %c", &t, &a);
		time += t;
		if (time >= 210) break;
		else {
			a == 'T' ? (bomb += 1) : (bomb += 0) ;
		}
	}
	printf("%d", bomb % 8 == 0 ? 8 : bomb % 8);
}

void main(void)
{
	int k;
	scanf("%d", &k);
	int n;
	scanf(" %d", &n);

	func(k, n);
}