#include<stdio.h>
#include<stdlib.h>
int first_sum[600000] = {0};
int second_sum[600000] = {0};
int array_a[1001] = {0};
int array_b[1001] = {0};
int compare(const void *a, const void *b) 
{
    return (*(int *)a - *(int *)b);
}
int main(void)
{
    long long ans = 0;
    int T;
    scanf("%d",&T);
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        {
            scanf("%d",&array_a[i]);
        }
    int m;
    scanf("%d",&m);
    for(int i=0; i<m; i++)
        {
            scanf("%d",&array_b[i]);
        }
    int s = 0;
    int dp = 0;
    for(int i=0; i<n; i++)
        {
            dp = 0;
            for(int j=i; j<n; j++)
                {
                    dp += array_a[j];
                    first_sum[s] = dp;
                    s += 1;
                }
        }
    int t = 0;
    for(int i=0; i<m; i++)
        {
            dp = 0;
            for(int j=i; j<m; j++)
                {
                    dp += array_b[j];
                    second_sum[t] = dp;
                    t += 1;
                }
        }
    qsort(first_sum, s, sizeof(int), compare);
    qsort(second_sum, t, sizeof(int), compare);
    int start = s - 1;
    int end = 0;
    while(start >= 0 && end < t)
        {
            if(first_sum[start] + second_sum[end] < T)
            {
                end += 1;
            }
            else if(first_sum[start] + second_sum[end] > T)
            {
                start -= 1;
            }
            else if(first_sum[start] + second_sum[end] == T)
            {
                long long len_a = 1;
                long long len_b = 1;
                while(start > 0)
                    {
                        if(first_sum[start] == first_sum[start-1])
                        {
                            len_a += 1;
                            start -= 1;
                        }
                        else
                        {
                            break;
                        }
                    }
                while(end < t - 1)
                    {
                        if(second_sum[end] == second_sum[end+1])
                        {
                            len_b += 1;
                            end += 1;
                        }
                        else
                        {
                            break;
                        }
                    }
                ans += len_a * len_b;
                start -= 1;
                end += 1;
            }
        }
    printf("%lld",ans);
}
