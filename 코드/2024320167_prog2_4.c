#include<stdio.h>
#include<stdlib.h>
void rremove(int n, int *target, int *count);
void add(int n, int *target, int x, int *count);
void push(int n, int *target, int direction, int *count);

int main(void)
{
    int test_count = 0;
    int normal_count = 0;
    int test[30001] = {0};
    int normal[10002] = {0};
    srand(1);
    for(int i=0; i<10000; i++)
    {
        normal[i] = i + 1;
    }
    int j = 1;
    for(int i=1; i<20000; i+=2)
    {
        test[i] = j;
        j += 1;
    }
    for(int i=0; i<10000; i++)
    {
        int pos = rand() % 10000;
        int temp = rand() % 10000 + 1;
        
        add(pos, normal, temp, &normal_count);
        int index = -1;
        for(int j=0; j<30001; j++)
        {
            if(test[j] != 0)
            {
                index += 1;
            }
            if(index == pos)
            {
                index = j;
                break;
            }
        }
        
        add(index, test, temp, &test_count);  
         
        pos = rand() % 10000;
        
        rremove(pos, normal, &normal_count);
        push(10001, normal, -1, &normal_count);
        index = -1;
        for(int j=0; j<30001; j++)
        {
            if(test[j] != 0)
            {
                index += 1;
            }
            if(index == pos)
            {
                index = j;
                break;
            }
        }
        rremove(index, test, &test_count);
        for(int j=0; j<10; j++)
        {
            pos = rand() % 10000;
            index = -1;
            for(int c=0; c<30001; c++)
            {
                if(test[c] != 0)
                {
                    index += 1;
                }
                if(index == pos)
                {
                    index = c;
                    break;
                }
            }
            if(normal[pos] == test[index])
            {
                continue;
            }
            else
            {
                printf("%d %d %d %d %d\n%d %d", pos, index, normal[pos], test[index],  i, normal_count, test_count);
                return 0;
            }
        }
    }
    printf("%d %d",normal_count, test_count);
}
void rremove(int n, int *target, int *count)
{
    target[n] = 0;
    (*count) += 1;
    return;
}
void push(int n, int *target, int direction, int *count)
{
    if(direction == -1)
    {
        if(n > 0 && target[n-1] == 0)
        {
            target[n-1] = target[n];
            target[n] = 0;
            (*count) += 2;
            return;
        }
        else if(n > 0)
        {
            push(n-1, target, direction, count);
            target[n-1] = target[n];
            target[n] = 0;
            (*count) += 2;
            return;
        }
    }
    else if(direction == 1)
    {
        if(n < 30000 && target[n+1] == 0)
        {
            target[n+1] = target[n];
            target[n] = 0;
            (*count) += 2;
            return;
        }
        else if(n < 30000)
        {
            push(n+1, target, direction, count);
            target[n+1] = target[n];
            target[n] = 0;
            (*count) += 2;
            return;
        }
    }
}
void add(int n, int *target, int x, int *count)
{
    if(target[n] == 0)
    {
        target[n] = x;
        (*count) += 1;
        return;
    }
    push(n, target, 1, count);
    target[n] = x;
    (*count) += 1;
    return;
}
