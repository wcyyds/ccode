#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
} node;

node *init(node *head)
{
    head = (node *)malloc(sizeof(node));
    head->next = NULL;
    return head;
}

void creatlist(node *head)
{
    int val;
    node *p = head;
    node *q = NULL;

    while (1)
    {
        scanf("%d", &val);
        if (val == 0)
        {
            break;
        }
        q = (node *)malloc(sizeof(node));
        q->val = val;
        p->next = q;
        p = p->next;
    }
    p->next = NULL;
}

node *TList(node *head)
{
    node *p;
    p = head->next;
    head->next = NULL;
    node *q;
    q->next = NULL;
    while (p != NULL)
    {
        q = p;
        p = p->next;
        q->next = head->next;
        head->next = q;
    }
    return head;
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




int main()
{
    node *head;
    head = init(head);
    creatlist(head);
    head = TList(head);
    printlist(head);
}