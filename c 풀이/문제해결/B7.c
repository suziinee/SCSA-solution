#include <stdio.h>

unsigned long long int x;
unsigned long long int y;
unsigned long long int ans;

int is_manbo(unsigned long long int num)
{
	char ch[20] = { '\0' };
	sprintf(ch, "%llu", num);

	int change = 0; 
	int tmp1 = -1; int tmp2 = -1; //index 저장
	for (int i = 0; i < 19; i++) {
		if (change >= 3) return 0;
		if (ch[i + 1] == '\0') break;
		if (ch[i] != ch[i + 1]) {
			if (tmp1 == -1) tmp1 = i;
			else tmp2 = i + 1;
			change++;
		}
	}

	if (change == 1) return 1;
	else if (change == 2) {
		if (ch[tmp1] == ch[tmp2]) return 1;
	}
	return 0;
}

void func(void)
{
	unsigned long long int i;
	for (i = x; i <= y; i++) {
		if (is_manbo(i)) ans++;
	}
}


void main(void)
{
	scanf("%llu %llu", &x, &y);
	func();
	printf("%llu", ans);
}