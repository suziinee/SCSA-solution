#include <stdio.h>
#include <string.h>

char a[210]; char b[210];
int ans[210];

void fill(int na, int nb)
{
	if (na > nb) { //b쪽에 0을 채움
		int rest = na - nb;
		for (int i = nb - 1; i >= 1; i--) {
			b[i + rest] = b[i];
		}
		for (int i = 1; i <= rest; i++) {
			b[i] = '0';
		}
	}
	else if (na < nb) { //a쪽에 0을 채움
		int rest = nb - na;
		for (int i = na - 1; i >= 1; i--) {
			a[i + rest] = a[i];
		}
		for (int i = 1; i <= rest; i++) {
			a[i] = '0';
		}
	}
}

int compare(int n) //a, b의 길이가 같을때 비교해주는 함수
{
	for (int i = 1; i < n; i++) {
		if (a[i] > b[i]) return 1;
		if (a[i] < b[i]) return -1;
	}
	return 0;
}

void plus(int n)
{
	int up = 0; int tmp;
	for (int i = n - 1; i >= 1; i--) {
		tmp = (a[i] - '0') + (b[i] - '0') + up;
		if (tmp >= 10) {
			up = 1;
			tmp -= 10;
			ans[i] = tmp;
		}
		else {
			up = 0;
			ans[i] = tmp;
		}
	}
	ans[0] = up;
	
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			if (ans[i] == 0) continue;
		}
		printf("%d", ans[i]);
	}
	printf("\n");
}

void minus(int n, int flag) //0이면 a가 더 크고 1이면 b가 더 큼
{
	int down[300] = { 0 };
	
	if (flag == 0) {
		for (int i = n - 1; i >= 1; i--) {
			int numa = a[i] - '0'; int numb = b[i] - '0';
			if (numa + down[i] >= numb) {
				ans[i] = numa + down[i] - numb;
			}
			else {
				int idx = i - 1;
				for (;;) {
					if (a[idx] != '0') break;
					idx--;
				}
				a[idx]--;
				down[i] = 10;
				for (int d = i - 1; d > idx; d--) down[d] = 9;
				ans[i] = numa + down[i] - numb;
			}
		}
	}
	else if (flag == 1) {
		for (int i = n - 1; i >= 1; i--) {
			int numa = a[i] - '0'; int numb = b[i] - '0';
			if (numb + down[i] >= numa) {
				ans[i] = numb + down[i] - numa;
			}
			else {
				int idx = i - 1;
				for (;;) {
					if (b[idx] != '0') break;
					idx--;
				}
				b[idx]--;
				down[i] = 10;
				for (int d = i - 1; d > idx; d--) down[d] = 9;
				ans[i] = numb + down[i] - numa;
			}
		}
	}
	int print_flag = 0; 
	for (int i = 1; i < n; i++) {
		if (ans[i] != 0) print_flag = 1;
		if (print_flag) printf("%d", ans[i]);
	}
	printf("\n");
}

void func(void)
{
	int na = strlen(a); int nb = strlen(b);
	
	for (int i = na - 1; i >= 0; i--) {
		a[i + 1] = a[i];
	}
	a[0] = '0';
	for (int i = nb - 1; i >= 0; i--) {
		b[i + 1] = b[i];
	}
	b[0] = '0';

	na++; nb++;

	if (na < nb) {
		fill(na, nb);
		plus(nb);
		minus(nb, 1);
	}
	else if (na > nb) {
		fill(na, nb);
		plus(na);
		minus(na, 0);
	}
	else if (na == nb) {
		fill(na, nb);
		plus(na);
		int i = compare(na);
		if (i == 1) minus(na, 0);
		else if (i == -1) minus(nb, 1);
		else if (i == 0) printf("0");
	}
}


void main(void)
{
	char ch;
	for (;;) {
		scanf(" %s", a);
		scanf(" %s", b);
		if ((a[0] == '0') && (b[0] == '0')) break;
		func();
	}
}



