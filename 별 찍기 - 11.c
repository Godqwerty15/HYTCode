#include<stdio.h>
int check(int n);
int ary[5000][7000] = {0};
int main(void)
{
    int n;
    scanf("%d",&n);
    int store = n - 1;
    n /= 3;
    ary[0][store] = 1;
    ary[1][store-1] = 1;
    ary[1][store+1] = 1;
    for(int j = store - 2; j <= store +2; j++)
        {
            ary[2][j] = 1;
        }
    int line = 3;
    for(int i=1; i<n; i++)
        {
            for(int j=0; j<3; j++)
                {
                    for(int c=0; c<2*store-1; c++)
                        {
                            if(ary[line-3*check(i)+j][c] == 1)
                            {
                                ary[line+j][c-3*check(i)] = 1;
                                ary[line+j][c+3*check(i)] = 1;
                            }
                        }
                }
            line += 3;
        }
    for(int i=0;i<store+1;i++)
        {
            for(int j=0;j<2*store+1; j++)
                {
                    if(ary[i][j] == 0)
                    {
                        printf(" ");
                    }
                    else
                    {
                        printf("*");
                    }
                }
            printf("\n");
        }
}
int check(int n)
{
    int i = 1;
    while(n>i)
        {
            if(i*2 > n)
            {
                return i;
            }
            else
            {
                i *= 2;
            }
        }
    return i;
}
