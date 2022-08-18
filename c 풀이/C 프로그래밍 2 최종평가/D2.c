#include <stdio.h>
#include <string.h>

char input[1000000 + 10];
char rev_res[1000000 + 10];
int carry;
int k = 1;

void output(void)
{
	int r = strlen(rev_res) - 1;
	if (rev_res[r] == '0') {
		printf("%d. IMPOSSIBLE\n", k);
	}
	else {
		printf("%d. ", k);
		for (int j = r; j >= 0; j--) {
			printf("%c", rev_res[j]);
		}
		printf("\n");
	}
}

int minus(int in, int r)
{
	int ret;

	if (input[in] == '0') {
		ret = 10 - carry - (rev_res[r] - '0');
		carry = 0;
	}
	else {
		if ((input[in] - '0') - carry >= (rev_res[r] - '0')) {
			ret = (input[in] - '0') - carry - (rev_res[r] - '0');
			carry = 0;
		}
		else {
			ret = 10 + (input[in] - '0' - carry) - (rev_res[r] - '0');
			carry = 1;
		}
	}
	return ret;
}

void solve(void)
{
	int in = strlen(input) - 1;
	int r = 0; //rev_res의 인덱스
	
	rev_res[r] = input[in];
	in--;

	while (in >= 0) {
		int tmp = minus(in, r);
		r++;
		rev_res[r] = tmp + '0';
		in--;
	}

	output();
}


void main(void)
{
	for (;;) {
		scanf("%s", input);
		if (input[0] == '0') break;
		solve();
		k++;
	}
}