#include <stdio.h>
#include <string.h>

int n;
char a[10000 + 10][20 + 5];
int flag[10000 + 10];

void func(void)
{
	int total_flag = 0; //한번도 바뀌지 않으면 unique
	
	for (int i = 0; i < n; i++) {
		if (flag[i] == 1) {
			int tmp[10000 + 10] = { 0, };
			int tmp_idx = 0;
			for (int j = i; j < n; j++) {
				int same = strcmp(a[i], a[j]);
				if ((flag[j] == 1) && (same == 0)) {
					tmp[tmp_idx++] = j;
					flag[j] = 0;
				}
			}
			if (tmp_idx >= 2) {
				printf("%s ", a[i]);
				for (int k = 0; k < tmp_idx; k++) printf("%d ", tmp[k]+1);
				printf("\n");
				total_flag = 1;
			}
		}
	}

	if (total_flag == 0) printf("unique");
}

void main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %s", a[i]);
		flag[i] = 1;
	}
	func();
}