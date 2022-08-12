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
        printf("%d*", p->val);
        p = p->next;
    }
}

node *add(node *head1, node *head2)
{
    node *newhead = NULL;
    node *newnewhead = (node *)malloc(sizeof(node));

    node *p1 = head1->next;
    node *p2 = head2->next;
    if (p1->val >= p2->val)
    {
        newhead = p2;
        p2 = p2->next;
    }
    else
    {
        newhead = p1;
        p1 = p1->next;
    }
    newnewhead->next = newhead;
    while (p1 != NULL && p2 != NULL)
    {
        if (p2->val >= p1->val)
        {
            newhead->next = p1;
            newhead = newhead->next;
            p1 = p1->next;
        }
        else
        {
            newhead->next = p2;
            newhead = newhead->next;
            p2 = p2->next;
        }
    }
    if (p1 == NULL)
    {
        newhead->next = p2;
    }
    else
    {
        newhead->next = p1;
    }
    return newnewhead->next;
}

int main()
{
    node *head1;
    head1 = init(head1);
    creatlist(head1);

    node *head2;
    head2 = init(head2);
    creatlist(head2);

    node *head;
    head = init(head);
    head->next = add(head1, head2);
    printlist(head);
}