#include <stdio.h>
#include <stdlib.h>

typedef struct node //链表
{
    int val;           //数据域
    struct node *next; //指针域
} Node;

Node *creatTail(Node **head) //尾插法创建链表
{
    int val;
    Node *p = *head;
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
        if (*head == NULL)
        {
            *head = q;
            p = q;
        }
        else
        {
            p->next = q;
            p = p->next;
        }
    }
    p->next = NULL;
}

void printList(Node *head) //链表遍历
{
    Node *p = head;
    while (p)
    {
        printf("%d", p->val);
        p = p->next;
    }
}



int main()
{
    Node *head = NULL; //链表
    creatTail(&head);  //头插法创建链表
    printList(head);   //链表的表达
    return 0;
}
