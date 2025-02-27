#include <stdio.h>
char ary[1002][1002] = {0};
int memo[1001][1001] = {0};
int check = 1;
int ans = 0;
void travel(int N, int M, int x, int y);
int main(void) 
{
    int N, M;
    scanf("%d%d",&N,&M);
    for(int i=0; i<N; i++)
        {
            char trash;
            scanf("%c",&trash);
            for(int j=0; j<M; j++)
                {
                    scanf("%c",&ary[i][j]);
                }
        }
    for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
                {
                    if(memo[i][j] == 0)
                    {
                        travel(N,M,i,j);
                        check += 1;
                    }
                }
        }
    printf("%d",ans);
}
void travel(int N, int M, int x, int y)
{
    memo[x][y] = check;
    if(ary[x][y] == 'D')
    {
        if(memo[x+1][y] == check)
        {
            ans += 1;
        }
        else if(memo[x+1][y] == 0)
        {
            travel(N, M, x+1, y);
        }
        else
        {

        }
    }
    else if(ary[x][y] == 'L')
    {
        if(memo[x][y-1] == check)
        {
            ans += 1;
        }
        else if(memo[x][y-1] == 0)
        {
            travel(N,M,x,y-1);
        }
        else
        {
            
        }
    }
    else if(ary[x][y] == 'U')
    {
        if(memo[x-1][y] == check)
        {
            ans += 1;
        }
        else if(memo[x-1][y] == 0)
        {
            travel(N,M,x-1,y);
        }
        else
        {
            
        }
    }
    else if(ary[x][y] == 'R')
    {
        if(memo[x][y+1] == check)
        {
            ans += 1;
        }
        else if(memo[x][y+1] == 0)
        {
            travel(N,M,x,y+1);
        }
        else
        {
            
        }
    }
}
