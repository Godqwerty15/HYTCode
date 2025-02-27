#include <stdio.h>
int ary[1001][1001] = {0};
int memo[1001][1001] = {0};
void bachu(int N, int M, int x, int y); //N행 M열ㄱ
void spread(int N, int M, int x, int y);
int ans(int N, int M, int x, int y);
int check = 1;
int num = -1;
int main() 
{
    int N, M;
    scanf("%d%d",&N,&M);
    for(int i=0; i<N; i++)
        {
            char trash;
            scanf("%c",&trash);
            for(int j=0; j<M; j++)
                {
                    scanf("%c",&trash);
                    if(trash == '1')
                    {
                        ary[i][j] = 1;
                    }
                    else if(trash == '0')
                    {
                        ary[i][j] = 0;
                    }
                }
        }
    for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
                {
                    if(ary[i][j] == 0)
                    {
                        bachu(N, M, i, j);
                        spread(N, M, i, j);
                        check = 1;
                        num -= 1;
                    }
                }
        }
    for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
                {
                    if(ary[i][j] == 1)
                    {
                        ary[i][j] = ans(N, M, i, j);
                    }
                }
        }
    for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
                {
                    if(ary[i][j] < 0)
                    {
                        printf("0");
                    }
                    else
                    {
                        printf("%d",ary[i][j]);
                    }
                }
            printf("\n");
        }
}
void bachu(int N, int M, int x, int y)
{
    ary[x][y] = num;
    if(x-1 >= 0)
    {
        if(ary[x-1][y] == 0)
        {
            if(memo[x-1][y] == 0)
            {
                check += 1;
                memo[x-1][y] = -1;
                
                bachu(N, M, x-1, y);
            }
        }
    }
    if(y-1 >= 0)
    {
        if(ary[x][y-1] == 0)
        {
            if(memo[x][y-1] == 0)
            {
                check += 1;
                memo[x][y-1] = -1;
                
                bachu(N, M, x, y-1);
            }
        }
    }
    if(x+1 < N)
    {
        if(ary[x+1][y] == 0)
        {
            if(memo[x+1][y] == 0)
            {
                check += 1;
                memo[x+1][y] = -1;
                
                bachu(N,M,x+1,y);
            }
        }
    }
    if(y+1 < M)
    {
        if(ary[x][y+1] == 0)
        {
            if(memo[x][y+1] == 0)
            {
                check += 1;
                memo[x][y+1] = -1;
                
                bachu(N,M,x,y+1);
            }
        }
    }
}
void spread(int N, int M, int x, int y)
{
    memo[x][y] = check;
    if(x-1 >= 0)
    {
            if(memo[x-1][y] == -1)
            {
                spread(N, M, x-1, y);
            }
    }
    if(y-1 >=0)
    {
            if(memo[x][y-1] == -1)
            {
                spread(N, M, x, y-1);
            }
    }
    if(x+1 < N)
    {
            if(memo[x+1][y] == -1)
            {
                spread(N, M, x+1, y);
            }
    }
    if(y+1 < M)
    {
            if(memo[x][y+1] == -1)
            {
                spread(N, M, x, y+1);
            }
    }
}
int ans(int N, int M, int x, int y)
{
    int temp = 0;
    int first = 0;
    int second = 0;
    int third = 0;
    int fourth = 0;
    if(x-1 >= 0)
    {
        if(ary[x-1][y] < 0)
        {
            first = ary[x-1][y];
            temp += memo[x-1][y];
        }
    }
    if(y-1 >= 0)
    {
        if(ary[x][y-1] < 0 && ary[x][y-1] != first)
        {
            second = ary[x][y-1];
            temp += memo[x][y-1];
        }
    }
    if(x+1 < N)
    {
        if(ary[x+1][y] < 0 && ary[x+1][y] != first && ary[x+1][y] != second)
        {
            third = ary[x+1][y];
            temp += memo[x+1][y];
        }
    }
    if(y+1 < M)
    {
        if(ary[x][y+1] < 0 && ary[x][y+1] != first && ary[x][y+1] != second && ary[x][y+1] != third)
        {
            fourth = ary[x][y+1];
            temp += memo[x][y+1];
        }
    }
    return (temp+1) % 10;
}
