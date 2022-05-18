#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int val;
    struct node *next;
} Node;

Node *init()
{
    Node *head;
    head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    return head;
}

void increatList(Node *head)
{
    Node *p = head;
    Node *q = NULL;
    int val;
    while (1)
    {
        scanf("%d", &val);
        if (val == 0)
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

Node *TList(Node *head)
{
    Node *p;//后移一格
    p = head->next;
    head->next = NULL;
    Node *q;
    q->next = NULL;//和头插一样，插的是q
    while (p != NULL)
    {
        q = p;//把q后移一个
        p = p->next;//记录后移的一个位置
        q->next = head->next;//头插q
        head->next = q;
    }
    return head;
}

void printList(Node *head)
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
    Node *head;
    head = init();
    increatList(head);
    head = TList(head);
    printList(head);
}