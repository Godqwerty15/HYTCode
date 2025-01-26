#include <stdio.h>
int main() 
{
    long long N, S, E;
    scanf("%lld%lld%lld",&N,&S,&E);
    double ans = 0;
    for(int i=0; i<N; i++)
        {
            long long R, A, D;
            scanf("%lld%lld%lld",&R,&A,&D);
            if(S % (R + A) > 0)
            {
                if(S % (R + A) <= R)
                {
                    if(E - S >= R + A - S % (R + A))
                    {
                        ans += D;
                    }
                    else if(E - S > R - S % (R + A))
                    {
                        ans += (E - S - R + S % (R + A)) / (double) A * D;
                    }
                }
                else
                {
                    if(E - S >= R + A - S % (R + A))
                    {
                        ans += (A - (S % (R + A)) + R) / (double) A * D;
                    }
                    else
                    {
                        ans += (E - S) / (double) A * D;
                    }
                }
                if(E - S - R - A + (S % (R + A)) > 0)
                {
                    ans += (E - S - R - A + (S % (R + A))) / (R + A) * D;
                    if((E - S - R - A + (S % (R + A))) % (R + A) > R)
                    {
                        ans += ((E - S - R - A + (S % (R + A))) % (R + A) - R) / (double) A * D;
                    }
                }
            }
            else
            {
                ans += (E - S) / (R + A) * D;
                if((E - S) % (R + A) > R)
                {
                    ans += ((E - S) % (R + A) - R) / (double) A * D;
                }
            }
        }
    ans /= (E - S);
    printf("%lf",ans);
}
