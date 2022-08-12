//队列
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 10
#define true 1
#define false 0

//***************************
typedef int Status; // Status是函数的类型
//***************************

//循环队列的顺序存储结构
typedef int QElemType;
typedef struct
{
    QElemType data[MAXSIZE];
    int front; //头指针
    int rear;  //尾指针，若队列不空，指向队列尾元素的下一个位置
} SqQueue;

//循环队列的初始化
//初始化一个空队列
Status InitQueue(SqQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    return true;
}

//循环队列求队列的长度
//返回Q的元素个数，也就是队列的当前长度
int QueueLength(SqQueue Q)
{
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

//循环队列入队列的操作
//若队列未满，则插入元素e为Q新的队尾元素
Status EnQueue(SqQueue *Q, QElemType e)
{
    if ((Q->rear + 1) % MAXSIZE == Q->front) //队列满的判断
    {
        return false;
    }
    Q->data[Q->rear] = e;              //将元素e赋值给队尾
    Q->rear = (Q->rear + 1) % MAXSIZE; //将rear指针向后移一位置
    //若到最后则转到数组头部
    return true;
}

//循环队列的出队操作
Status DeQueue(SqQueue *Q, QElemType *e)
{
    if (Q->front == Q->rear) //队列空的判断
    {
        return false;
    }
    *e = Q->data[Q->front];              //将队头元素赋值给e
    Q->front = (Q->front + 1) % MAXSIZE; // front指针向后移一位置
    //若到最后则转到数组头部
    return true;
}

int main()
{
    SqQueue *q;
    InitQueue(q);
    QElemType e;
    int n = 0;
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &e);
        EnQueue(q, e); //给队列输入5个数字
    }
    n = QueueLength(*q);
    printf("*%d*", n); //输出现在队列的长度

    DeQueue(q, &e);
    printf("---%d---", e); //出队列

    n = QueueLength(*q);
    printf("**%d**", n); //输出现在队列的长度
}
