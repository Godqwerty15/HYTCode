#include<stdio.h>
int memo[10][101][1024] = {0};
int main(void)
{
    int N;
    scanf("%d",&N);
    for(int i=1; i<10; i++)
    {
        memo[i][1][1 << i] = 1;
    }
    for(int i=1; i<N; i++)
    {
        for(int j=0; j<10; j++)
        {
            for(int c=1; c<1024; c++)
            {
                if(j == 0)
                {
                    long long temp = memo[j+1][i+1][c | (1 << (j+1))] + memo[j][i][c];
                    temp %= 1000000000;
                    memo[j+1][i+1][c | (1 << (j+1))] = (int)temp;
                }
                else if(j > 0 && j < 9)
                {
                    long long temp = memo[j+1][i+1][c | (1 << (j+1))] + memo[j][i][c];
                    temp %= 1000000000;
                    memo[j+1][i+1][c | (1 << (j+1))] = (int)temp;
                    temp = memo[j-1][i+1][c | (1 << (j-1))] + memo[j][i][c];
                    temp %= 1000000000;
                    memo[j-1][i+1][c | (1 << (j-1))] = (int)temp;
                }
                else if(j == 9)
                {
                    long long temp = memo[j-1][i+1][c | (1 << (j-1))] + memo[j][i][c];
                    temp %= 1000000000;
                    memo[j-1][i+1][c | (1 << (j-1))] = (int)temp;
                }
            }
        }
    }
    long long ans = 0;
    for(int i=0; i<10; i++)
    {
        ans += memo[i][N][1023];
    }
    printf("%lld",ans % 1000000000);
}
