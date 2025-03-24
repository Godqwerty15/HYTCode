#include<stdio.h>
int piv(long long n);
int main(void)
{
    long long a;
    scanf("%lld",&a);
    int temp = piv(a);
    int temp2 = piv(a+1);
    while(temp<0)
        {
            temp += 1000000007;
        }
   while(temp2 < 0)
   {
      temp2 += 1000000007;
   }
   long long ans = (long long)temp * (long long)temp2 % 1000000007;
    printf("%lld",ans);
}
int piv(long long n)
{
    long long dp[2500] = {0};
    int s = 0;
    int ord[500]={-1};
    while(n!=1)
        {
            if(n%2==0)
            {
                n/=2;
                ord[s]=0;
                s++;
            }
            else
            {
                n/=2;
                ord[s]=1;
                s++;
            }
        }
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    int t = 1;
    for(int i=s-1;i>=0;i--)
        {
            t+=3;
            if(ord[i]==0)
            {
                dp[t] = (dp[t-3] * (2*dp[t-4] + dp[t-3])) % 1000000007;
                dp[t-1] = (dp[t-4] * dp[t-4] + dp[t-3] * dp[t-3]) % 1000000007;
                dp[t+1] = (dp[t-3] * dp[t-3] + dp[t-2] * dp[t-2]) % 1000000007;
            }
            else if(ord[i]==1)
            {
                dp[t] = (dp[t-3] * dp[t-3] + dp[t-2] * dp[t-2]) % 1000000007;
                dp[t-1] = (dp[t-3] * (2*dp[t-4] + dp[t-3])) % 1000000007;
                dp[t+1] = (dp[t] + dp[t-1]) % 1000000007;
            }
        }
    return dp[t];
}
