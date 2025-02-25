#include <stdio.h>
int ddr[100001][5][5] = {0};
int data[100001] = {0};
int main() 
{
    int c = 0;
    while(1)
        {
            int ary;
            scanf("%d",&ary);
            if(ary != 0)
            {
                data[c] = ary;
                c += 1;
            }
            else
            {
                break;
            }
        }
    ddr[0][data[0]][0] = 2;
    ddr[0][0][data[0]] = 2;
    int i= 0;
    while(1)
        {
            if(data[i+1] == 0)
            {
                break;
            }
            for(int j=0; j<5; j++)
                {
                    for(int v=0; v<5; v++)
                        {
                            if(ddr[i][j][v] != 0)
                            {
                                if(data[i+1] == j)
                                {
                                    if(ddr[i+1][j][v] == 0 || ddr[i+1][j][v] > ddr[i][j][v] + 1)
                                    {
                                        ddr[i+1][j][v] = ddr[i][j][v] + 1;
                                    }
                                }
                                if(data[i+1] == v)
                                {
                                    if(ddr[i+1][j][v] == 0 || ddr[i+1][j][v] > ddr[i][j][v] + 1)
                                    {
                                        ddr[i+1][j][v] = ddr[i][j][v] + 1;
                                    }
                                }
                                if(j != data[i+1])
                                {
                                    if(v == 0)
                                {
                                    if(ddr[i+1][j][data[i+1]] == 0 || ddr[i+1][j][data[i+1]] > ddr[i][j][v] + 2)
                                    {
                                        ddr[i+1][j][data[i+1]] = ddr[i][j][v] + 2;
                                    }
                                }
                                else if(v + data[i+1] != 4 && v + data[i+1] != 6)
                                {
                                    if(ddr[i+1][j][data[i+1]] == 0 || ddr[i+1][j][data[i+1]] > ddr[i][j][v] + 3)
                                    {
                                        ddr[i+1][j][data[i+1]] = ddr[i][j][v] + 3;
                                    }
                                }
                                else if(v + data[i+1] == 4 || v + data[i+1] == 6)
                                {
                                    if(ddr[i+1][j][data[i+1]] == 0 || ddr[i+1][j][data[i+1]] > ddr[i][j][v] + 4)
                                    {
                                        ddr[i+1][j][data[i+1]] = ddr[i][j][v] + 4;
                                    }
                                }
                                }
                                if(v != data[i+1])
                                {
                                    if(j == 0)
                                {
                                    if(ddr[i+1][data[i+1]][v] == 0 || ddr[i+1][data[i+1]][v] > ddr[i][j][v] + 2)
                                    {
                                        ddr[i+1][data[i+1]][v] = ddr[i][j][v] + 2;
                                    }
                                }
                                else if(j + data[i+1] != 4 && j + data[i+1] != 6)
                                {
                                    if(ddr[i+1][data[i+1]][v] == 0 || ddr[i+1][data[i+1]][v] > ddr[i][j][v] + 3)
                                    {
                                        ddr[i+1][data[i+1]][v] = ddr[i][j][v] + 3;
                                    }
                                }
                                else if(j + data[i+1] == 4 || j + data[i+1] == 6)
                                {
                                    if(ddr[i+1][data[i+1]][v] == 0 || ddr[i+1][data[i+1]][v] > ddr[i][j][v] + 4)
                                    {
                                        ddr[i+1][data[i+1]][v] = ddr[i][j][v] + 4;
                                    }
                                }
                                }
                            }
                        }
                }
            i += 1;
        }
    c -= 1;
    int small = 100000000;
    for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
                {
                    if(small > ddr[c][i][j] && ddr[c][i][j] != 0)
                    {
                        small = ddr[c][i][j];
                    }
                }
        }
    printf("%d",small);
}
