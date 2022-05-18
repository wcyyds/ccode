#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	int data[5];
	int top;
} SqStack;

//插入元素e为新的栈顶元素
void Push(SqStack *S, int e)
{
	if (S->top == 5 - 1)
	{
		printf("栈已满\n");
		return 0;
	}
	S->top++;
	S->data[S->top] = e;
	printf("插入成功\n");
	return 0;
}

//若栈不为空，则删除S的栈顶元素，用e返回其值；否则返回栈已满
void Pop(SqStack *S, int *e)
{
	if (S->top == -1)
	{
		printf("栈已满\n");
		return 0;
	}
	*e = S->data[S->top];
	S->top--;
	printf("删除成功\n");
	return 0;
}

//查看栈的内容
void printstack(SqStack *S)
{
	int i;
	for (i = 0; i < 5; i++)
	{
		printf("%d", S->data[i]);
	}
}

int main()
{
	SqStack *stack = (SqStack *)malloc(sizeof(SqStack));
	stack->top = -1;
	printstack(stack);
}