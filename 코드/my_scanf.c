#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdarg.h>
#define MAX 3000
//EOF는 이미 -1로 선언돼 있네. 큐가 빈 경우. 
#define Format_ERROR -2 //형식이 잘못됐음.
#define Type_ERROR -3 //자료형 내에서 오류가 발생함.
#define QueueOverflow_ERROR -4 //큐가 꽉 찼음.
typedef struct{
    char items[MAX];
    int front;
    int rear;
} queue;
void init(queue* q)
{
    q -> front = -1;
    q -> rear = -1;
}
int isEmpty(queue* q)
{
    if(q -> front == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(queue* q)
{
    if(q -> rear == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enque(queue* q, char item)
{
    if(isFull(q))
    {
        return;
    }
    if(q -> front == -1)
    {
        q -> front = 0;
    }
    q -> rear ++;
    q -> items[q -> rear] = item;
}
char deque(queue* q)
{
    if(isEmpty(q))
    {
        return '\0';
    }
    char item = q -> items[q -> front];
    if(q -> front == q-> rear)
    {
        q -> front = -1;
        q -> rear = -1;
    }
    else
    {
        q -> front += 1;
    }
    return item;
}
int isDigit(char c) {
    return c >= '0' && c <= '9';
}
int Int_greater(const char* str)
{
    const char* max_str = "2147483647";

    if(strlen(str) < strlen(max_str))
    {
        return 0;
    }
    return strcmp(str, max_str) > 0;
}
int Short_greater(const char* str)
{
    const char* max_str = "32767";
    if(strlen(str) < strlen(max_str))
    {
        return 0;
    }
    return strcmp(str, max_str) > 0;
}
int SC_greater(const char *str)
{
    const char* max_str = "127";
    if(strlen(str) < strlen(max_str))
    {
        return 0;
    }
    return strcmp(str, max_str) > 0;
}
int my_scanf(queue* q, const char* format, ...)
{
    va_list args;
    va_start(args, format);

    const char* ptr = format;
    int count = 0;

    char str[MAX];
    if(isEmpty(q))
    {
        fgets(str, sizeof(str), stdin);
    
        int pos = 0;

        while(str[pos] != '\0')
        {
            if(isFull(q))
            {
                return QueueOverflow_ERROR;
            }
            enque(q, str[pos]);
            pos += 1;
    }
    }
    while(*ptr)
    {
        if(*ptr == '%')
        {
            ptr++;
            if(*ptr == 'd')
            {
                char temp[12];
                int i;
                for(i=0; i<11; i++)
                {
                    char check = deque(q);
                    if(check == '\0' && i == 0)
                    {
                        return EOF;
                    }
                    else if(check == '\0' || check == ' ' || check == '\n')
                    {
                        break;
                    }
                    else if(isDigit(check))
                    {
                        temp[i] = check;
                    }
                    else if(check == '-')
                    {
                        if(i == 0)
                        {
                            temp[i] = check;
                        }
                        else
                        {
                            return Type_ERROR;
                        }
                    }
                    else if(!isDigit(check))
                    {
                        return Type_ERROR;
                    }
                }
                temp[i] = '\0';
                if(temp[0] == '-')
                {
                    char temp2[15];
                    int j = 0;
                    for(j=0; j<=i-1; j++)
                    {
                        temp2[j] = temp[j+1];
                    }
                    temp2[j] = '\0';
                    if(!Int_greater(temp2))
                    {
                        int* num = va_arg(args, int*);
                        *num = atoi(temp2) * (-1);
                        count += 1;
                    }
                    else
                    {
                        return Type_ERROR;
                    }
                }
                else
                {
                    if(!Int_greater(temp))
                    {
                        int* num = va_arg(args, int*);
                        *num = atoi(temp);
                        count += 1;
                    }
                    else
                    {
                        return Type_ERROR;
                    }
                }
                continue;
            }
            else if(*ptr == 's')
            {
                char temp[MAX];
                int i = 0;
                for(i=0; i<MAX-1; i++)
                {
                    char check;
                    if(q -> front != -1)
                    {
                        if(q -> items[q -> front] != '\n')
                        {
                            check = deque(q);
                            temp[i] = check;
                        }
                        else
                        {
                            break;
                        }
                    }
                    else if(q -> front == -1 && i == 0)
                    {
                        return EOF;
                    }
                    else if(q -> front == -1 && i != 0)
                    {
                        break;
                    }
                }
                temp[i] = '\0';
                char* text = va_arg(args, char*);
                strcpy(text, temp);
                count += 1;
                continue;
            }
            else if(*ptr == 'c')
            {
                char temp;
                if(q -> front != -1)
                {
                    temp = deque(q);
                }
                char *text = va_arg(args, char*);
                *text = temp;
                count += 1;
                continue;
            }
            else if(*ptr == 'f')
            {
                char temp[50];
                int i = 0;
                int pointCheck = 0;
                for(i=0; i<49; i++)
                {
                    char check = deque(q);
                    if(check == '\0' && i == 0)
                    {
                        return EOF;
                    }
                    else if(check == '\0' || check == ' ' || check == '\n')
                    {
                        break;
                    }
                    else if(isDigit(check))
                    {
                        temp[i] = check;
                    }
                    else if(check == '-')
                    {
                        if(i == 0)
                        {
                            temp[i] = check;
                        }
                        else
                        {
                            return Type_ERROR;
                        }
                    }
                    else if(check == '.')
                    {
                        if(pointCheck == 0)
                        {
                            pointCheck = 1;
                            temp[i] = check;
                        }
                        else
                        {
                            return Type_ERROR;
                        }
                    }
                }
                temp[i] = '\0';
                float* num = va_arg(args, float*);
                *num = strtof(temp, NULL);
                count += 1;
                continue;
            }
            else if(*ptr == 'l')
            {
                ptr++;
                if(*ptr == 'd')
                {
                    char temp[12];
                    int i;
                    for(i=0; i<11; i++)
                    {
                        char check = deque(q);
                        if(check == '\0' && i == 0)
                        {
                            return EOF;
                        }
                        else if(check == '\0' || check == ' ' || check == '\n')
                        {
                            break;
                        }
                        else if(isDigit(check))
                        {
                            temp[i] = check;
                        }
                        else if(check == '-')
                        {
                            if(i == 0)
                            {
                                temp[i] = check;
                            }
                            else
                            {
                                return Type_ERROR;
                            }
                        }
                        else if(!isDigit(check))
                        {
                            return Type_ERROR;
                        }
                    }
                    temp[i] = '\0';
                    if(temp[0] == '-')
                    {
                        char temp2[15];
                        int j = 0;
                        for(j=0; j<=i-1; j++)
                        {
                            temp2[j] = temp[j+1];
                        }
                        temp2[j] = '\0';
                        if(!Int_greater(temp2))
                        {
                            int* num = va_arg(args, int*);
                            *num = atoi(temp2) * (-1);
                            count += 1;
                        }
                        else
                        {
                            return Type_ERROR;
                        }
                    }
                    else
                    {
                        if(!Int_greater(temp))
                        {
                            int* num = va_arg(args, int*);
                            *num = atoi(temp);
                            count += 1;
                        }
                        else
                        {
                            return Type_ERROR;
                        }
                    }
                    continue;
                }
                else if(*ptr == 'f')
                {
                    char temp[325];
                    int i = 0;
                    int pointCheck = 0;
                    for(i=0; i<324; i++)
                    {
                        char check = deque(q);
                        if(check == '\0' && i == 0)
                        {
                            return EOF;
                        }
                        else if(check == '\0' || check == ' ' || check == '\n')
                        {
                            break;
                        }
                        else if(isDigit(check))
                        {
                            temp[i] = check;
                        }
                        else if(check == '-')
                        {
                            if(i == 0)
                            {
                                temp[i] = check;
                            }
                            else
                            {
                                return Type_ERROR;
                            }
                        }
                        else if(check == '.')
                        {
                            if(pointCheck == 0)
                            {
                                pointCheck = 1;
                                temp[i] = check;
                            }
                            else
                            {
                                return Type_ERROR;
                            }
                        }
                    }
                    temp[i] = '\0';
                    double* num = va_arg(args, double*);
                    *num = atof(temp);
                    count += 1;
                    continue;
                }
            }
            else if(*ptr == 'h')
            {
                ptr++;
                if(*ptr == 'h')
                {
                    ptr++;
                    if(*ptr == 'd')
                    {
                        char temp[5];
                        int i;
                        for(i=0; i<4; i++)
                        {
                            char check = deque(q);
                            if(check == '\0' && i == 0)
                            {
                                return EOF;
                            }
                            else if(check == '\0' || check == ' ' || check == '\n')
                            {
                                break;
                            }
                            else if(isDigit(check))
                            {
                                temp[i] = check;
                            }
                            else if(check == '-')
                            {
                                if(i == 0)
                                {
                                    temp[i] = check;
                                }
                                else
                                {
                                    return Type_ERROR;
                                }
                            }
                            else if(!isDigit(check))
                            {
                                return Type_ERROR;
                            }
                        }
                        temp[i] = '\0';
                        if(temp[0] == '-')
                        {
                            char temp2[15];
                            int j = 0;
                            for(j=0; j<=i-1; j++)
                            {
                                temp2[j] = temp[j+1];
                            }
                            temp2[j+1] = '\0';
                            if(!SC_greater(temp2))
                            {
                                int* num = va_arg(args, int*);
                                *num = atoi(temp2) * (-1);
                                count += 1;
                            }
                            else
                            {
                                return Type_ERROR;
                            }
                        }
                        else
                        {
                            if(!SC_greater(temp))
                            {
                                int* num = va_arg(args, int*);
                                *num = atoi(temp);
                                count += 1;
                            }
                            else
                            {
                                return Type_ERROR;
                            }
                        }
                        continue;
                    }
                }
                else if(*ptr == 'd')
                {
                    char temp[7];
                        int i;
                        for(i=0; i<6; i++)
                        {
                            char check = deque(q);
                            if(check == '\0' && i == 0)
                            {
                                return EOF;
                            }
                            else if(check == '\0' || check == ' ' || check == '\n')
                            {
                                break;
                            }
                            else if(isDigit(check))
                            {
                                temp[i] = check;
                            }
                            else if(check == '-')
                            {
                                if(i == 0)
                                {
                                    temp[i] = check;
                                }
                                else
                                {
                                    return Type_ERROR;
                                }
                            }
                            else if(!isDigit(check))
                            {
                                return Type_ERROR;
                            }
                        }
                        temp[i] = '\0';
                        if(temp[0] == '-')
                        {
                            char temp2[15];
                            int j = 0;
                            for(j=0; j<=i-1; j++)
                            {
                                temp2[j] = temp[j+1];
                            }
                            temp2[j] = '\0';
                            if(!Short_greater(temp2))
                            {
                                int* num = va_arg(args, int*);
                                *num = atoi(temp2) * (-1);
                                count += 1;
                            }
                            else
                            {
                                return Type_ERROR;
                            }
                        }
                        else
                        {
                            if(!Short_greater(temp))
                            {
                                int* num = va_arg(args, int*);
                                *num = atoi(temp);
                                count += 1;
                            }
                            else
                            {
                                return Type_ERROR;
                            }
                        }
                        continue;
                }
            }
            else
            {
                return Format_ERROR;
            }
        }
        ptr++;
    }
    va_end(args);
    return count;
}
int main(void)
{
    queue q;
    init(&q);
    int a;
    float b;
    double c;
    char text[10];
    int result = my_scanf(&q, "%d %f",&a, &b);
    printf("%d %f\n",a, b);
    my_scanf(&q, "%lf",&c);
    printf("%lf\n",c);
    if(result < 0)
    {
        printf("에러여부 : %d", result);
    }
    else
    {
        printf("처음에 성공한 입력 : %d\n", result);
    }
    my_scanf(&q, "%s", text); //%s 입력을 개행문자로 끊으면, 버퍼에 남아있던 개행 문자가 %c 입력으로 바로 들어간다.
    printf("%s\n",text);
    char temp;
    my_scanf(&q, "%c", &temp);
    printf("%c\n",temp);
}
