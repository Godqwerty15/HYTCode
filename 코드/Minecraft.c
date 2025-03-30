#include<stdio.h>
int ary[100][100][100];
char H[101][101];
char R[101][101];
char C[101][101];
int main(void)
{
    int n;
    scanf("%d",&n);
    for(int j=0; j<n; j++)
    {
        char trash;
        scanf("%c",&trash);
        for(int k=0; k<n; k++)
        {
            scanf("%c",&H[j][k]);
        }
    }
    for(int i=0; i<n; i++)
    {
        char trash;
        scanf("%c",&trash);
        for(int k=0; k<n; k++)
        {
            scanf("%c",&R[i][k]);
        }
    }
    for(int i=0; i<n; i++)
    {
        char trash;
        scanf("%c",&trash);
        for(int j=0; j<n; j++)
        {
            scanf("%c",&C[i][j]);
        }
    }
    for(int j=0; j<n; j++)
    {
        for(int k=0; k<n; k++)
        {
            if(H[j][k] == '1')
            {
                int temp = 0;
                for(int i=0; i<n; i++)
                {
                    if(R[i][k] == '1' && C[i][j] == '1')
                    {
                        ary[i][j][k] = 1;
                        temp = 1;
                    }
                }
                if(temp == 0)
                {
                    printf("NO");
                    return 0;
                }
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int k=0; k<n; k++)
        {
            if(R[i][k] == '1')
            {
                int temp = 0;
                for(int j=0; j<n; j++)
                {
                    if(H[j][k] == '1' && C[i][j] == '1')
                    {
                        ary[i][j][k] = 1;
                        temp = 1;
                    }
                }
                if(temp == 0)
                {
                    printf("NO");
                    return 0;
                }
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(C[i][j] == '1')
            {
                int temp = 0;
                for(int k=0; k<n; k++)
                {
                    if(H[j][k] == '1' && R[i][k] == '1')
                    {
                        ary[i][j][k] = 1;
                        temp = 1;
                    }
                }
                if(temp == 0)
                {
                    printf("NO");
                    return 0;
                }
            }
        }
    }
    printf("YES\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<n; k++)
            {
                printf("%d", ary[i][j][k]);
            }
            printf("\n");
        }
    }
}
