#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
} Node;

Node *increatList(Node **head)
{
    Node *p = *head;
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

void printList(Node *head)
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
    Node *head = NULL;
    increatList(&head);
    printList(head);
    return 0;
}
