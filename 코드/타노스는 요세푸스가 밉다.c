#include <stdio.h>
int ary[2][1000001] = {0};
int main() 
{
    int N, K;
    scanf("%d%d",&N,&K);
    for(int i=0; i<N; i++)
        {
            if(i == N-1)
            {
                ary[0][i] = 0;
            }
            else
            {
                ary[0][i] = i + 1;
            }
            if(i == 0)
            {
                ary[1][i] = N - 1;
            }
            else
            {
                ary[1][i] = i - 1;
            }
        }
    int s = N;
    int start = 0;
    while(1)
        {
            if(s < K)
            {
                printf("%d", start + 1);
                break;
            }
            else
            {
                start = ary[0][start];
            }
            for(int i=0; i<K-1; i++)
                {
                    ary[1][ary[0][start]] = ary[1][start];
                    ary[0][ary[1][start]] = ary[0][start];
                    s -= 1;
                    start = ary[0][start];
                }
        }
}
