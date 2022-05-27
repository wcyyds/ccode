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

#include<stdio.h>
#include<string.h>
int main()
{
    char s[] = {"())"};
    int right = 0;
    int left = 0;
    for(int i = 0; i < (strlen(s) - 2); i++)
    {
        if(s[i] == ')')
        {
            left++;
        }
        if(s[i] == '(')
        {
            left++;
        }
    }
    if((right - left) >= 0)
    {
        printf("%d",right - left);
    }
    else
    {
        printf("%d",left - right);
    }
}