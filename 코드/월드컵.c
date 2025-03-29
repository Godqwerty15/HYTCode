#include<stdio.h>
int ary[4][18] = {0};
int check[18] = {0};
int ans[4] = {0,0,0,0};
void world(int i, int j, int x);
int main(void)
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<18; j++)
        {
            scanf("%d",&ary[i][j]);
        }
    }
    for(int i=0; i<4; i++)
    {
        world(0, 1, i);
    }
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<6; j++)
        {
            if(ary[i][j*3] + ary[i][j*3+1] + ary[i][j*3+2] != 5)
            {
                ans[i] = 0;
            }
        }
    }
    printf("%d %d %d %d",ans[0], ans[1], ans[2], ans[3]);
}
void world(int i, int j, int x)
{
    if(check[i*3] < ary[x][i*3] && check[j*3+2] < ary[x][j*3+2])
    {
        if(i == 4)
        {
            ans[x] = 1;
            return;
        }
        check[i*3] += 1;
        check[j*3+2] += 1;
        if(j < 5)
        {
            world(i, j+1, x);
        }
        else
        {
            world(i+1, i+2, x);
        }
        check[i*3] -= 1;
        check[j*3+2] -= 1;
    }
    if(check[i*3+1] < ary[x][i*3+1] && check[j*3+1] < ary[x][j*3+1])
    {
        if(i == 4)
        {
            ans[x] = 1;
            return;
        }
        check[i*3+1] += 1;
        check[j*3+1] += 1;
        if(j < 5)
        {
            world(i, j+1, x);
        }
        else
        {
            world(i+1, i+2, x);
        }
        check[i*3+1] -= 1;
        check[j*3+1] -= 1;
    }
    if(check[i*3+2] < ary[x][i*3+2] && check[j*3] < ary[x][j*3])
    {
        if(i == 4)
        {
            ans[x] = 1;
            return;
        }
        check[i*3+2] += 1;
        check[j*3] += 1;
        if(j < 5)
        {
            world(i, j+1, x);
        }
        else
        {
            world(i+1, i+2, x);
        }
        check[i*3+2] -= 1;
        check[j*3] -= 1;
    }
}
