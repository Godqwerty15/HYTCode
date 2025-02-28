#include <stdio.h>
long long query[40000001] = {0};
int Eu(int x, int y);
long long permi(long long x);
int main() 
{
    long long test = 1;
    for(int i=1; i<=40000000; i++)
        {
            test *= i;
            test %= 1000000007;
            query[i] = test;
        }
    query[0] = 1;
    int M,N,K;
    scanf("%d",&M);
    for(int j=0; j<M; j++)
        {
            scanf("%d%d",&N,&K);
            long long temp = 1;
            long long store = 1;
            long long plus = 1;
            if(N == 1)
            {
                printf("1\n");
                continue;
            }
            plus = query[K];
            temp = query[N];
            store = query[N-K];
            long long t = permi(store);
            temp *= t;
            temp %= 1000000007;
            long long x = permi(plus);
            temp *= x;
            temp %= 1000000007;
            printf("%lld\n",temp);
        }
}
long long permi(long long x)
{
    long long memo[30] = {0};
    memo[0] = x;
    for(int i=1; i<30; i++)
        {
            memo[i] = memo[i-1] * memo[i-1];
            memo[i] %= 1000000007;
        }
    long long temp = 1;
    int list[15] = {29, 28, 27, 25, 24, 23, 20, 19, 17, 15, 14, 11, 9, 2, 0};
    for(int i=0; i<15; i++)
        {
            temp *= memo[list[i]];
            temp %= 1000000007;
        }
    return temp;
}
