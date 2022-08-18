#include <stdio.h>

int n; 
int ans;

int pow(int num, int len) //num은 자릿수, len은 뒷자리 개수
{
	int ret = 1;
	for (int i = 0; i < len; i++)
		ret *= 9;
	if (num < 3) return ret * num;
	else return ret * (num - 1);
}

void func(void)
{
	char ch[10] = { '\0' };
	sprintf(ch, "%d", n);
	int len = strlen(ch);

	//첫번째~마지막 전 숫자 처리
	for (int i = 0; i < len - 1; i++) {
		ans += pow(ch[i] - '0', len - (i + 1));
	}

	//마지막 숫자 처리
	if (ch[len - 1] < '3') {
		ans += ch[len - 1] - '0' + 1;
	}
	else {
		ans += ch[len - 1] - '0';
	}
}


void main(void)
{
	scanf("%d", &n);
	func();
	printf("%d", ans - 1);
}
