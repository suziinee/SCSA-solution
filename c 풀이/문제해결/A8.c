#include <stdio.h>

typedef struct st {
	int x;
	int y;
	int d;
	int num;
}AXIS;
AXIS a[100 + 10];
AXIS dong;
int n, m;
int store;
int ans;


void change(void)
{
	switch (dong.d) {
		case 1: dong.x = dong.num; dong.y = m; break;
		case 2: dong.x = dong.num; dong.y = 0; break; 
		case 3: dong.x = 0; dong.y = m - dong.num; break;
		case 4: dong.x = n; dong.y = m - dong.num; break;
	}

	for (int i = 0; i < store; i++) {
		switch (a[i].d) {
		case 1: a[i].x = a[i].num; a[i].y = m; break;
		case 2: a[i].x = a[i].num; a[i].y = 0; break;
		case 3: a[i].x = 0; a[i].y = m - a[i].num; break;
		case 4: a[i].x = n; a[i].y = m - a[i].num; break;
		}
	}
}

int abs(int x, int y)
{
	if (x < y) return y - x;
	else return x - y;
}

void func(void)
{
	for (int i = 0; i < store; i++) {
		int left = 0; int right = 0;
		if (abs(a[i].d, dong.d) == 1) {
			left = a[i].x + a[i].y + dong.x + dong.y;
		}
		else {
			left = abs(a[i].x, dong.x) + abs(a[i].y, dong.y);
		}
		right = 2 * n + 2 * m - left;
		ans += ((left < right) ? left : right);
	}
}


void main(void)
{
	scanf("%d %d %d", &n, &m, &store);
	for (int i = 0; i < store; i++) {
		scanf("%d %d", &a[i].d, &a[i].num);
	}
	scanf("%d %d", &dong.d, &dong.num);
	change();
	func();
	printf("%d", ans);
}