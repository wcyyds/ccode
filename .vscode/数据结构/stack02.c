#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 15

typedef char SElemType;
typedef struct
{
    SElemType data[MAXSIZE];
    int top;
} SqStack;

bool visit(SElemType c);              //输出一个元素
bool InitStack(SqStack *S);           //初始化栈
bool ClearStack(SqStack *S);          //清空栈
bool StackEmpty(SqStack S);           //判断栈是否为空
int StackLength(SqStack S);           //求栈的长度
bool GetTop(SqStack S, SElemType *e); //获取栈顶元素
bool Push(SqStack *S, SElemType e);   //压栈
bool Pop(SqStack *S, SElemType *e);   //弹出栈
bool StackTraverse(SqStack S);        //从栈底元素依次输出栈

int main()
{
    int j;
    SqStack s;
    SElemType e;
    if (InitStack(&s) == true)
    {
        for (j = 1; j <= 15; j++)
        {
            Push(&s, j);
        }
    }
    printf("栈中元素依次为：\n");
    StackTraverse(s);

    Pop(&s, &e);

    printf("弹出的栈顶元素 e=%d\n", e);
    printf("栈空否：%d(1:空 0:否)\n", StackEmpty(s));
    GetTop(s, &e);
    printf("栈顶元素 e=%d 栈的长度为%d\n", e, StackLength(s));
    ClearStack(&s);
    printf("清空栈后，栈空否：%d(1:空 0:否)\n", StackEmpty(s));

    return 0;
}

//初始化栈
bool InitStack(SqStack *S)
{
    S->top = -1;

    return true;
}

//清空栈
bool ClearStack(SqStack *S)
{
    S->top = -1;

    return true;
}

//判断栈是否为空
bool StackEmpty(SqStack S)
{
    if (S.top == -1)
        return true;
    else
        return false;
}

//获取栈顶元素
bool GetTop(SqStack S, SElemType *e)
{
    if (StackEmpty(S))
    {
        return false;
    }
    *e = S.data[S.top];
    return true;
}

//压栈
bool Push(SqStack *S, SElemType e)
{
    if (S->top == MAXSIZE - 1)
    {
        return false;
    }
    S->top++;
    S->data[S->top] = e;
    return true;
}

//弹出栈
bool Pop(SqStack *S, SElemType *e)
{
    if (S->top == -1)
    {
        return false;
    }
    *e = S->data[S->top];
    S->top--;
    return true;
}

//从栈底依次输出每个元素
bool StackTraverse(SqStack S)
{
    int i = 0;

    while (i <= S.top)
    {
        visit(S.data[i++]);
    }
    printf("\n");
    return true;
}

//输出一个元素
bool visit(SElemType c)
{
    printf("%d\n", c);

    return true;
}

//求栈的长度
int StackLength(SqStack S)
{
    return (S.top + 1);
}
