#include <stdio.h>
#include <string.h>

int L;
char S[20000];
int n;

void input(void)
{
	scanf("%d", &n);
	scanf("%s", S);
}

void solve(void)
{
	int len = strlen(S);

	for (int i = 0; i < len; ) {
		if (S[i] == '<') {
			L++; i++;
		}
		else if (S[i] == '>') {
			L--; i++;
		}
		else { //숫자일 경우
			char num[4] = { '\0' }; int c = 0;
			for (;;) {
				num[c++] = S[i++];
				if (S[i] == '<' || S[i] == '>') break;
			}
			if (L == n) printf("%d ", atoi(num));
		}
	}
}


int main(void)
{
	input();
	solve();
	return 0;
}