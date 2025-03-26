#include<stdio.h>
#include<stdlib.h>
int power(int x)
{
    int temp = 1;
    for(int i=0; i<x; i++)
    {
        temp *= 2;
    }
    return temp;
}
void draw2(int *ary, int width, int height)
{
    char example[height][width];
    char output[height][width];
    for(int i=0; i<width; i++)
    {
        for(int j=height - 1; j>=0; j--)
        {
            if(ary[i] >= power(j))
            {
                ary[i] -= power(j);
                example[j][i] = 'W';
            }
            else
            {
                example[j][i] = ' ';
            }
        }
    }
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            if(i > 0 && i < height - 1 && j > 0 && j < width - 1)
            {
                if(example[i][j] == 'W')
                {
                    if(example[i][j-1] == 'W' && example[i][j+1] == 'W' && example[i-1][j] == ' ' && example[i+1][j] == ' ')
                    {
                        output[i][j] = '-';
                    }
                    else if(example[i][j-1] == ' ' && example[i][j+1] == ' ' && example[i-1][j] == 'W' && example[i+1][j] == 'W')
                    {
                        output[i][j] = '|';
                    }
                    else
                    {
                        output[i][j] = '+';
                    }
                }
                else
                {
                    output[i][j] = ' ';
                }
            }
            else if(i == 0)
            {
                if(example[i+1][j] == 'W')
                {
                    output[i][j] = '+';
                }
                else
                {
                    output[i][j] = '-';
                }
            }
            else if(i == height - 1)
            {
                if(example[i-1][j] == 'W')
                {
                    output[i][j] = '+';
                }
                else
                {
                    output[i][j] = '-';
                }
            }
            else if(j == 0)
            {
                if(example[i][j+1] == 'W')
                {
                    output[i][j] = '+';
                }
                else
                {
                    output[i][j] = '|';
                }
            }
            else if(j == width - 1)
            {
                if(example[i][j-1] == 'W')
                {
                    output[i][j] = '+';
                }
                else
                {
                    output[i][j] = '|';
                }
            }
        }
    }
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            printf("%c",output[i][j]);
        }
        printf("\n");
    }
}
void draw(int *ary, int width, int height)
{
    char example[height][width];
    char output[height][width];
    for(int i=0; i<height; i++)
    {
        for(int j=width - 1; j>=0; j--)
        {
            if(ary[i] >= power(j))
            {
                ary[i] -= power(j);
                example[i][j] = 'W';
            }
            else
            {
                example[i][j] = ' ';
            }
        }
    }
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            if(i > 0 && i < height - 1 && j > 0 && j < width - 1)
            {
                if(example[i][j] == 'W')
                {
                    if(example[i][j-1] == 'W' && example[i][j+1] == 'W' && example[i-1][j] == ' ' && example[i+1][j] == ' ')
                    {
                        output[i][j] = '-';
                    }
                    else if(example[i][j-1] == ' ' && example[i][j+1] == ' ' && example[i-1][j] == 'W' && example[i+1][j] == 'W')
                    {
                        output[i][j] = '|';
                    }
                    else
                    {
                        output[i][j] = '+';
                    }
                }
                else
                {
                    output[i][j] = ' ';
                }
            }
            else if(i == 0)
            {
                if(example[i+1][j] == 'W')
                {
                    output[i][j] = '+';
                }
                else
                {
                    output[i][j] = '-';
                }
            }
            else if(i == height - 1)
            {
                if(example[i-1][j] == 'W')
                {
                    output[i][j] = '+';
                }
                else
                {
                    output[i][j] = '-';
                }
            }
            else if(j == 0)
            {
                if(example[i][j+1] == 'W')
                {
                    output[i][j] = '+';
                }
                else
                {
                    output[i][j] = '|';
                }
            }
            else if(j == width - 1)
            {
                if(example[i][j-1] == 'W')
                {
                    output[i][j] = '+';
                }
                else
                {
                    output[i][j] = '|';
                }
            }
        }
    }
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            printf("%c",output[i][j]);
        }
        printf("\n");
    }
}
int main(void)
{
    FILE *file = fopen("maze1-1.txt", "r");
    
    int width, height;
    fscanf(file, "%d%d", &width, &height);
    int ch;
    while ((ch = fgetc(file)) != '\n' && ch != EOF);

    char maze[height][width];

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            maze[i][j] = fgetc(file);
        }
        while ((ch = fgetc(file)) != '\n' && ch != EOF);
    }
    fclose(file);
    if(width < 32)
    {
    int *ary = (int *)malloc(height * sizeof(int));
    for(int i=0; i<height; i++)
    {
        ary[i] = 0;
    }
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            if(maze[i][j] == '+' || maze[i][j] == '|' || maze[i][j] == '-')
            {
                ary[i] += power(j);
            }
        }
    }
    draw(ary, width, height);
    }
    else if(height < 32)
    {
        int *ary = (int *)malloc(width * sizeof(int));
        for(int i=0; i<width; i++)
        {
            ary[i] = 0;
        }
        for(int i=0; i<width; i++)
        {
            for(int j=0; j<height; j++)
            {
                if(maze[j][i] == '+' || maze[j][i] == '|' || maze[j][i] == '-')
                {
                    ary[i] += power(j);
                }
            }
        }
        draw2(ary, width, height);
    }
}
