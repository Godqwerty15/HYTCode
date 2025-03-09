#include <stdio.h>
int queue[2][10000000] = {0};
int memo[2][500001] = {0};
int brother[500001] = {0};
int main(void)
{
    int N, K;
    scanf("%d%d",&N,&K);
    int t = 0, s = 0, ans = 100000000;
    queue[0][s] = N;
    if(N == K)
    {
        printf("0");
        return 0;
    }
    if(K > 500000)
    {
        printf("-1");
        return 0;
    }
    s += 1;
    int count = 1000002;
    while(1)
        {
            int temp = queue[1][t];
            if(temp % 2 == 0)
            {
            if(queue[0][t] != 0 && queue[0][t] <= 250000)
            {
                if(memo[0][queue[0][t] - 1] == 0)
                {
                    memo[0][queue[0][t] - 1] = temp + 1;
                    count -= 1;
                    queue[0][s] = queue[0][t] - 1;
                    queue[1][s] = temp + 1;
                    s += 1;
                }
                if(memo[0][queue[0][t] + 1] == 0)
                {
                    memo[0][queue[0][t] + 1] = temp + 1;
                    count -= 1;
                    queue[0][s] = queue[0][t] + 1;
                    queue[1][s] = temp + 1;
                    s += 1;
                }
                if(memo[0][queue[0][t] * 2] == 0)
                {
                    memo[0][queue[0][t] * 2] = temp + 1;
                    count -= 1;
                    queue[0][s] = queue[0][t] * 2;
                    queue[1][s] = temp + 1;
                    s += 1;
                }
                if(count == 0)
                {
                    break;
                }
                t += 1;
            }
            else if(queue[0][t] == 0)
            {
                if(memo[0][queue[0][t] + 1] == 0)
                {
                    memo[0][queue[0][t] + 1] = temp + 1;
                    count -= 1;
                    queue[0][s] = queue[0][t] + 1;
                    queue[1][s] = temp + 1;
                    s += 1;
                }
                if(count == 0)
                {
                    break;
                }
                t += 1;
            }
            else if(queue[0][t] > 250000 && queue[0][t] < 500000)
            {
                if(memo[0][queue[0][t] - 1] == 0)
                {
                    memo[0][queue[0][t] - 1] = temp + 1;
                    count -= 1;
                    queue[0][s] = queue[0][t] - 1;
                    queue[1][s] = temp + 1;
                    s += 1;
                }
                if(memo[0][queue[0][t] + 1] == 0)
                {
                    memo[0][queue[0][t] + 1] = temp + 1;
                    count -= 1;
                    queue[0][s] = queue[0][t] + 1;
                    queue[1][s] = temp + 1;
                    s += 1;
                }
                if(count == 0)
                {
                    break;
                }
                t += 1;
            }
            else if(queue[0][t] == 500000)
            {
                if(memo[0][queue[0][t] - 1] == 0)
                {
                    memo[0][queue[0][t] - 1] = temp + 1;
                    count -= 1;
                    queue[0][s] = queue[0][t] - 1;
                    queue[1][s] = temp + 1;
                    s += 1;
                }
                if(count == 0)
                {
                    break;
                }
                t += 1;
            }
            }
            else
            {
            if(queue[0][t] != 0 && queue[0][t] <= 250000)
            {
                if(memo[1][queue[0][t] - 1] == 0)
                {
                    memo[1][queue[0][t] - 1] = temp + 1;
                    count -= 1;
                    queue[0][s] = queue[0][t] - 1;
                    queue[1][s] = temp + 1;
                    s += 1;
                }
                if(memo[1][queue[0][t] + 1] == 0)
                {
                    memo[1][queue[0][t] + 1] = temp + 1;
                    count -= 1;
                    queue[0][s] = queue[0][t] + 1;
                    queue[1][s] = temp + 1;
                    s += 1;
                }
                if(memo[1][queue[0][t] * 2] == 0)
                {
                    memo[1][queue[0][t] * 2] = temp + 1;
                    count -= 1;
                    queue[0][s] = queue[0][t] * 2;
                    queue[1][s] = temp + 1;
                    s += 1;
                }
                if(count == 0)
                {
                    break;
                }
                t += 1;
            }
            else if(queue[0][t] == 0)
            {
                if(memo[1][queue[0][t] + 1] == 0)
                {
                    memo[1][queue[0][t] + 1] = temp + 1;
                    count -= 1;
                    queue[0][s] = queue[0][t] + 1;
                    queue[1][s] = temp + 1;
                    s += 1;
                }
                if(count == 0)
                {
                    break;
                }
                t += 1;
            }
            else if(queue[0][t] > 250000 && queue[0][t] < 500000)
            {
                if(memo[1][queue[0][t] - 1] == 0)
                {
                    memo[1][queue[0][t] - 1] = temp + 1;
                    count -= 1;
                    queue[0][s] = queue[0][t] - 1;
                    queue[1][s] = temp + 1;
                    s += 1;
                }
                if(memo[1][queue[0][t] + 1] == 0)
                {
                    memo[1][queue[0][t] + 1] = temp + 1;
                    count -= 1;
                    queue[0][s] = queue[0][t] + 1;
                    queue[1][s] = temp + 1;
                    s += 1;
                }
                if(count == 0)
                {
                    break;
                }
                t += 1;
            }
            else if(queue[0][t] == 500000)
            {
                if(memo[1][queue[0][t] - 1] == 0)
                {
                    memo[1][queue[0][t] - 1] = temp + 1;
                    count -= 1;
                    queue[0][s] = queue[0][t] - 1;
                    queue[1][s] = temp + 1;
                    s += 1;
                }
                if(count == 0)
                {
                    break;
                }
                t += 1;
            }
            }
        }
    for(int i=1; i<1000; i++)
        {
            if(K + i <= 500000)
            {
                brother[K + i] = i;
                if(memo[0][K + i] <= i)
                {
                    if((i - memo[0][K + i]) % 2 == 0)
                    {
                        if(ans > i)
                        {
                            ans = i;
                        }
                    }
                }
                if(memo[1][K + i] <= i)
                {
                    if((i - memo[1][K + i]) % 2 == 0)
                    {
                        if(ans > i)
                        {
                            ans = i;
                        }
                    }
                }
                K += i;
            }
            else
            {
                break;
            }
        }
    if(ans == 100000000)
    {
        printf("-1");
    }
    else
    {
        printf("%d",ans);
    }
}
