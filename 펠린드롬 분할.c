#include<stdio.h>
#include<stdbool.h>
#include<string.h>
bool fellin[2500][2500] = {false};
int memo[2500] = {0};
int check(int n, int s);
int main(void)
{
    char str[2500];
    scanf("%s",str);
    int n = strlen(str);
    for(int i=0; i<n; i++)
        {
            fellin[i][i] = true;
        }
    for(int i=1; i<n; i++)
        {
            if(str[i] == str[i-1])
            {
                fellin[i][i-1] = true;
                fellin[i-1][i] = true;
            }
        }
    for(int i=1; i<n; i++)
        {
            for(int j=i; j<n; j++)
                {
                    if(str[j-i] == str[j])
                    {
                        if(fellin[j-i+1][j-1])
                        {
                            fellin[j-i][j] = true;
                        }
                    }
                }
        }
    //이제 함수를 만들어야 되는데.. ㅎ
    printf("%d",check(n, 0));
}
int check(int n, int s)
{
    int ans = 5000;
    int test;
    for(int i=s; i<n; i++)
        {
            if(fellin[s][i])
            {
                if(i == n-1)
                {
                    test = 1;
                }
                else if(memo[i+1] != 0)
                {
                    test = memo[i+1] + 1;
                }
                else
                {
                    test = check(n, i+1) + 1;
                }
                if(test < ans)
                {
                    ans = test;
                }
            }
        }
    memo[s] = ans;
    return memo[s];
}
