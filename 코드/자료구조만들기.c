#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    int **intAry;
    float **floatAry;
    char ***strAry;
    int a, b, c;
} assignment;
int main(void)
{
    assignment Assign;
    scanf("%d%d%d",&Assign.a,&Assign.b,&Assign.c);
    
    Assign.intAry = malloc(Assign.a * sizeof(int *));
    for(int i=0; i<Assign.a; i++)
    {
        Assign.intAry[i] = malloc(Assign.b * sizeof(int));
    }

    Assign.floatAry = malloc(Assign.b * sizeof(float *));
    for(int i=0; i<Assign.b; i++)
    {
        Assign.floatAry[i] = malloc(Assign.c * sizeof(float)); 
    }

    Assign.strAry = malloc(Assign.c * sizeof(char **));
    for(int i=0; i<Assign.c; i++)
    {
        Assign.strAry[i] = malloc(Assign.a * sizeof(char *));
        for(int j=0; j<Assign.a; j++)
        {
            Assign.strAry[i][j] = malloc(4 * sizeof(char));
        }
    }

    int intTemp = 1;
    for(int i=0; i<Assign.a; i++)
    {
        for(int j=0; j<Assign.b; j++)
        {
            Assign.intAry[i][j] = intTemp;
            intTemp += 1;
            printf("%d ", Assign.intAry[i][j]);
        }
        printf("\n");
    }
    
    float floatTemp = 1.0;
    for(int i=0; i<Assign.b; i++)
    {
        for(int j=0; j<Assign.c; j++)
        {
            Assign.floatAry[i][j] = floatTemp;
            floatTemp += 0.1;
            printf("%.1f ", Assign.floatAry[i][j]);
        }
        printf("\n");
    }

    char strTemp[4] = "hi1";
    for(int i=0; i<Assign.c; i++)
    {
        for(int j=0; j<Assign.a; j++)
        {
            strcpy(Assign.strAry[i][j], strTemp);
            strTemp[2] += 1;
            if(strTemp[2] == ':')
            {
                strTemp[2] = '0';
            }
            printf("%s ", Assign.strAry[i][j]);
        }
        printf("\n");
    }

    for(int i=0; i<Assign.a; i++)
    {
        free(Assign.intAry[i]);
    }
    free(Assign.intAry);
    for(int i=0; i<Assign.b; i++)
    {
        free(Assign.floatAry[i]);
    }
    free(Assign.floatAry);
    for(int i=0; i<Assign.c; i++)
    {
        for(int j=0; j<Assign.a; j++)
        {
            free(Assign.strAry[i][j]);
        }
        free(Assign.strAry[i]);
    }
    free(Assign.strAry);
}
