#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef struct node
{
    int date;
    struct node *next;
} Node;Node *head;

void place()
{
    head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
}

void cratelist(Node *head)
{
    Node t;
    Node *s = head;
    Node *r;
    while (1)
    {
        scanf("%d", &t.date);
        if (t.date == 0)
            break;
        r = (Node *)malloc(sizeof(Node));
        *r = t;

        s->next = r;
        s = r;
        s->next = NULL;
    }
    s->next = NULL;
}

Node *resetlist(Node *head)
{
    Node *p = head, *q = NULL;
    while (p != NULL)
    {
        Node *t = p->next;
        p->next = q;
        q = p;
        p = t;
    }
    return q;
}

void outPut(Node *head)
{
    Node *p = head;
    while (p->next != NULL)
    {
        printf("%d\n", p->date);
        p = p->next;
    }
}

int main()
{
    place();
    cratelist(head);
    head = resetlist(head);
    outPut(head);
    return 0;
}