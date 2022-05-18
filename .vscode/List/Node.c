#include <stdio.h>
#include <stdlib.h>

typedef struct node //链表
{
    int val;           //数据域
    struct node *next; //指针域
} Node;

Node *init() //创造头结点
{
    Node *head;
    head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    return head;
}

void creatTail(Node *head) //尾插法创建链表
{
    int val;
    Node *p = head;
    Node *q = NULL;
    while (1)
    {
        scanf("%d", &val);
        if (val == -1)
        {
            break;
        }
        q = (Node *)malloc(sizeof(Node));
        q->val = val;
        p->next = q;
        p = p->next;
    }
    p->next = NULL;
}

void printList(Node *head) //链表遍历
{
    Node *p = head;
    p = p->next;
    while (p)
    {
        printf("%d", p->val);
        p = p->next;
    }
}

int main()
{
    Node *head;      //链表
    head = init();   //给头结点分配地址
    creatTail(head); //尾插法创建链表
    printList(head); //链表的表达
    return 0;
}
