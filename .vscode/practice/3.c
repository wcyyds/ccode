#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int val;
    struct Node *next;
} node;

node *init()
{
    node *head;
    head = (node *)malloc(sizeof(node));
    head->next = NULL;
    return head;
}

void creatlist(node *head)
{
    int val;
    node *newhead;
    while (1)
    {
        scanf("%d", &val);
        if (val == 0)
        {
            break;
        }
        newhead = (node *)malloc(sizeof(node));
        newhead->val = val;
        newhead->next = NULL;
        newhead->next = head->next;
        head->next = newhead;
    }
}

void printlist(node *head)
{
    node *p = head;
    p = p->next;
    while (p)
    {
        printf("%d", p->val);
        p = p->next;
    }
}

node *tlist(node *head)
{
    node *p;
    p = head->next;
    head->next = NULL;
    node *q;
    q->next;
    while (p != NULL)
    {
        q = p;
        p = p->next;
        p->next = head->next;
        head->next = p;
    }
    return head;
}

int main()
{
    node *head;
    head = init();
    creatlist(head);
    head = tlist(head);
    printlist(head);
}