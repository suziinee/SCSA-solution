#include <stdio.h>

int func(int start, int n, int p_time[], char* tpf)
{
    int bomb=start;
    int time=0;

    for (int i=start; i<start+n; i++) {
        time+=p_time[i];
        p_time[i]=0;
        if (time<210) {
            if (tpf[i]=='T') bomb+=1;
        }
        else return (bomb%8)==0 ? 8 : bomb%8;
    }
    return (bomb%8)==0 ? 8 : bomb%8;
}

void main(void)
{
    int p_time[1000]={0}; char tpf[1000] = {'A'};

    int start;
    scanf("%d", &start);
    int n;
    scanf(" %d", &n);

    for (int i=0; i<n; i++) {
        scanf(" %d %s", &p_time[start+i], &tpf[start+i]);
    }
    printf("%d", func(start, n, p_time, tpf));

}