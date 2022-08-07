#include <stdio.h>

int n, m;
int x, y;

//더 작은 수를 앞의 포인터에 넣음
void func(int *p, int *q)
{
	int tmp;
	
	if ((*p) > (*q)) {
		tmp = *p; 
		*p = *q; 
		*q = tmp;
	}
}

int is_cross(void)
{
	if ((n < x) && (m > x)) {
		if (m < y) return 1;
	}
	if ((x < n) && (y > n)) {
		if (y < m) return 1;
	}
	return 0;
}

void main(void)
{
	scanf("%d %d", &n, &m);
	scanf("%d %d", &x, &y);
	func(&n, &m);
	func(&x, &y);
	if (is_cross()) printf("cross");
	else printf("not cross");
}