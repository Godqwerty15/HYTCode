#include<stdio.h>
#include<stdlib.h>
int memo[501][500] = {0};
int ary[500][2] = {0};
int min(int x, int y);
int dis(int x, int y);
int main(void)
{
   int N, K;
   scanf("%d%d",&N,&K);
   for(int i=0; i<501; i++)
   {
      for(int j=0; j<500; j++)
      {
         memo[i][j] = -1;
      }
   }
   for(int i=0; i<N; i++)
   {
      scanf("%d%d",&ary[i][0], &ary[i][1]);
   }
   memo[K][0] = 0;
   for(int i=1; i<N; i++)
   {
      memo[K][i] = memo[K][i-1] + abs(ary[i][0] - ary[i-1][0]) + abs(ary[i][1] - ary[i-1][1]);
   }
   for(int i=K-1; i>=0; i--)
   {
      for(int j=0; j<N; j++)
      {
         int temp = 1;
         while(j - temp - 1 >= 0 && i + temp <= K)
         {
            if(memo[i+temp][j-temp-1] == -1)
            {
               temp += 1;
               continue;
            }
            if(memo[i][j] == -1)
            {
               memo[i][j] = memo[i+temp][j-temp-1] + dis(j-temp-1, j);
            }
            else
            {
               if(dis(j-temp-1,j) + memo[i+temp][j-temp-1] < memo[i][j])
               {
                  memo[i][j] = dis(j-temp-1,j) + memo[i+temp][j-temp-1];
               }
            }
            temp += 1;
         }
         if(memo[i][j-1] != -1)
         {
            if(memo[i][j-1] + dis(j-1,j) < memo[i][j])
            {
               memo[i][j] = memo[i][j-1] + dis(j-1,j);
            }
         }
      }
   }
   int ans = 100000000;
   for(int i=0; i<=K; i++)
   {
      if(ans > memo[i][N-1] && memo[i][N-1] != -1)
      {
         ans = memo[i][N-1];
      }
   }
   printf("%d",ans);
}
int min(int x, int y)
{
   if(x > y)
   {
      return y;
   }
   else
   {
      return x;
   }
}
int dis(int x, int y)
{
   return abs(ary[x][0] - ary[y][0]) + abs(ary[x][1] - ary[y][1]);
}
