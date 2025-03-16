#include<stdio.h>
#include<stdlib.h>
int compare(const void *a, const void *b) 
{
   return (*(int*)a - *(int*)b);  
}
int ary[1000000] = {0};
int ans[1000000] = {0};
int main(void)
{
   int N;
   scanf("%d",&N);
   for(int i=0; i<N; i++)
   {
      scanf("%d",&ary[i]);
   }
   qsort(ary, N, sizeof(int), compare);
   if(N % 2 == 0)
   {
      int temp = N - 1;
      for(int i=1; i<N; i+=2)
      {
         ans[i] = ary[temp];
         temp -= 1;
      }
      ans[0] = ary[N / 2 - 1];
      temp = 0;
      for(int i=2; i<N; i+=2)
      {
         ans[i] = ary[temp];
         temp += 1;
      }
      long long sum = 0;
      for(int i=0; i<N-1; i++)
      {
         sum += abs(ans[i] - ans[i+1]);
      }
      printf("%lld",sum);
   }
   else
   {
      int temp = N - 1;
      for(int i=1; i<N; i+=2)
      {
         ans[i] = ary[temp];
         temp -= 1;
      }
      ans[0] = ary[N / 2];
      ans[N-1] = ary[N / 2 - 1];
      temp = 0;
      for(int i=2; i<N-1; i+=2)
      {
         ans[i] = ary[temp];
         temp += 1;
      }
      long long sum = 0;
      for(int i=0; i<N-1; i++)
      {
         sum += abs(ans[i] - ans[i+1]);
      }
      ans[0] = ary[N / 2];
      ans[N-1] = ary[N / 2 + 1];
      temp = N - 1;
      for(int i=2; i<N-1; i+=2)
      {
         ans[i] = ary[temp];
         temp -= 1;
      }
      temp = 0;
      for(int i=1; i<N; i+=2)
      {
         ans[i] = ary[temp];
         temp += 1;
      }
      long long sum2 = 0;
      for(int i=0; i<N-1; i++)
      {
         sum2 += abs(ans[i] - ans[i+1]);
      }
      if(sum > sum2)
      {
         printf("%lld",sum);
      }
      else
      {
         printf("%lld",sum2);
      }
   }
}
