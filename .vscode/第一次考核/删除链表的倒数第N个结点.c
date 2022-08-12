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

node *deletelist(node *head, int n)
{
    
    int i;
    node *p = head->next;
    node *q = head;
    while (p)
    {
        p = p->next;
        i++;
    }

    int j;
    for (j = 0; j < (i - n); j++)
    {
        q = q->next;
    }
    q->next = q->next->next;

    return head;
}

int main()
{
    node *head;
    head = init(head);
    creatlist(head);
    int n;
    scanf("%d", &n);
    head = deletelist(head, n);
    printf("\n\n");
    printlist(head);
}