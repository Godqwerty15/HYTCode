#include <stdio.h>
int down_col[500001] = {0};
int up_col[500001] = {0};
int down_memo[500001] = {0};
int up_memo[500001] = {0};
int main() 
{
    int N, H;
    scanf("%d%d",&N,&H);
    for(int i=0; i<N; i++)
        {
            if(i % 2 == 0)
            {
                int temp;
                scanf("%d",&temp);
                down_col[temp] += 1;
            }
            else
            {
                int temp;
                scanf("%d",&temp);
                up_col[temp] += 1;
            }
        }
    down_memo[H] = down_col[H];
    up_memo[H] = up_col[H];
    for(int i=H-1; i>0; i--)
        {
            down_memo[i] = down_col[i] + down_memo[i+1];
            up_memo[i] = up_col[i] + up_memo[i+1];
        }
    int min = 1000000;
    int s = 0;
    for(int i=1; i<=H; i++)
        {
            if(down_memo[i] + up_memo[H-i+1] < min)
            {
                min = down_memo[i] + up_memo[H-i+1];
                s = 1;
            }
            else if(down_memo[i] + up_memo[H-i+1] == min)
            {
                s += 1;
            }
        }
    printf("%d %d", min, s);
}
