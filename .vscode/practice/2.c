// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
// int *dailyTemperatures(int *temperatures, int temperaturesSize, int *returnSize)
// {
//     int *res = (int *)malloc(sizeof(int) * temperaturesSize); //储存结果
//     int stack[temperaturesSize + 1];                          //栈用于储存元素下标
//     *returnSize = temperaturesSize;
//     int top = -1; //栈顶指针

//     for (int i = 0; i < temperaturesSize; ++i)
//     { //遍历数组
//         while (top != -1 && temperatures[i] > temperatures[stack[top]])//遍历的元素与栈顶下标元素所指的温度进行比较
//         {
//             res[stack[top]] = i - stack[top]; //大于则获取天数并将栈顶元素取出
//             --top;
//         }
//         stack[++top] = i; //将遍历的元素下标压入栈
//     }
//     while (top > -1) //栈中剩余下标元素所指的天数为零
//         res[stack[top--]] = 0;

//     return res;
// }
// int main()
// {
//     //测试
// }

#include <stdio.h>
#include <string.h>
int main()
{
    char s[] = {"3+2*2"};
    int n = strlen(s);
    int i = 0;
    int strack[5] = {0};
    int top = 0;
    int num = 0;
    int zhengshu = 0;

    for (i; i < n; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            zhengshu = zhengshu * 10 + (s[i] - '0');
        }
        else
        {
            if (s[i] == '+')
            {
                strack[top] = zhengshu;
                top++;
            }
            else if (s[i] == '-')
            {
                strack[top] = -zhengshu;
                top++;
            }
            else if (s[i] == '*')
            {
                strack[top - 1] *= zhengshu;
            }
            else if (s[i] == '/')
            {
                strack[top - 1] /= zhengshu;
            }
            zhengshu = 0;
        }
    }
    top--;
    while (top >= 0)
    {
        num += strack[top];
        top--;
    }
    return num;
}

int calculate(char *s)
{
    int len = strlen(s);
    int i;
    char ch;
    char sign = '+';
    int num = 0;
    int res = 0;
    int top = 0;
    int stack[len];

    for (i = 0; i <= len; i++)
    {
        ch = s[i];
        if (ch >= '0' && ch <= '9')
        {
            num = num * 10 + (ch - '0');
        }
        else
        {
            if (ch == ' ')
            {
                continue;
            }
            if (sign == '+')
            {
                stack[top++] = num;
            }
            else if (sign == '-')
            {
                stack[top++] = -num;
            }
            else if (sign == '*')
            {
                stack[top - 1] *= num;
            }
            else if (sign == '/')
            {
                stack[top - 1] /= num;
            }
            sign = ch;
            num = 0;
        }
    }

    while (top > 0)
    {
        res += stack[--top];
    }
    return res;
}
