#include <stdio.h>
int ary[6000] = {0};
int store[2][6000] = {0};
int main() 
{
    int N, K, Q, M;
    scanf("%d%d%d%d",&N,&K,&Q,&M);
    for(int i=0; i<K; i++)
        {
            int sleep;
            scanf("%d",&sleep);
            ary[sleep] = -1;
        }
    for(int i=0; i<Q; i++)
        {
            int check, temp;
            scanf("%d",&check);
            temp = check;
            if(ary[temp] == -1)
            {
                continue;
            }
            while(check <= 5100)
                {
                    if(ary[check] == -1)
                    {
                        check += temp;
                    }
                    else
                    {
                        ary[check] = 1;
                        check += temp;
                    }
                }
        }
    int s = 0;
    for(int i=3; i<=N+2; i++)
        {
            if(ary[i] == 0 || ary[i] == -1)
            {
                s += 1;
                store[0][i] = s;
            }
            store[0][i] = s;
        }
    s = 0;
    for(int i=N+2; i>=3; i--)
        {
            if(ary[i] == 0 || ary[i] == -1)
            {
                s += 1;
            }
            store[1][i] = s;
        }
    for(int i=0; i<M; i++)
        {
            int start, end;
            scanf("%d%d",&start,&end);
            printf("%d\n",store[0][N+2] - store[0][start-1] - store[1][end+1]);
        }
}
