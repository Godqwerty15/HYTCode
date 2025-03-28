#include<stdio.h>
#include<string.h>
int cost[16][16] = {0};
int memo[16][65536] = {0};
void travel(int n, int x, int N, int s, int start, int target);
void gB(int N, int n, int current, int start, int no);
int target = 1;
int main(void)
{
    int N;
    scanf("%d",&N);
    int ans = 1000000000;
    for(int i=0; i<N; i++)
    {
        target *= 2;
    }
    target -= 1;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }
    for(int i=0; i<N; i++)
    {
        memset(memo, 0, sizeof(memo));
        travel(i, 0, N, 0, i, target ^ (1 << i));
        for(int j=1; j<N; j++)
        {
            gB(N, j, 0, 0, i);
        }
        if(ans > memo[i][target] && memo[i][target] != 0)
        {
            ans = memo[i][target];
        }
    }
    printf("%d",ans);
}
void travel(int n, int x, int N, int s, int start, int target)
{
    if(x == target && cost[n][start] != 0)
    {
        if(memo[start][target | (1 << start)] == 0)
        {
            memo[start][target | (1 << start)] = memo[n][x] + cost[n][start];
        }
        else if(memo[start][target | (1 << start)] > memo[n][x] + cost[n][start])
        {
            memo[start][target | (1 << start)] = memo[n][x] + cost[n][start];
        }
    }
    else
    {
    for(int i=0; i<N; i++)
    {
        if(cost[n][i] != 0 && i != start)
        {
            if(x & (1 << i))
            {
                continue;
            }
            else
            {
                int temp = x | (1 << i);
                if(memo[i][temp] == 0)
                {
                    memo[i][temp] = s + cost[n][i];
                }
                else if(memo[i][temp] > s + cost[n][i])
                {
                    memo[i][temp] = s + cost[n][i];
                }
            }
        }
    }
    }
}
void gB(int N, int n, int current, int start, int no) 
{
    if (n == 0) 
    {
        for(int i=0; i<N; i++)
        {
            if(current & (1 << i) && memo[i][current] != 0)
            {
                travel(i, current, N, memo[i][current], no, target ^ (1 << no));
            }
        }
        return;
    }
    for (int i = start; i < N; i++) 
    {
        if(i != no)
        {
            gB(N, n - 1, current | (1 << i), i + 1, no);
        }
    }
}
