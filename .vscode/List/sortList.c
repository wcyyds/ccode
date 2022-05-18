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

node *bubblesort(node *Head)
{
    node *pfirst = NULL, *pend = NULL;
    pfirst = Head->next;
    int temp;
    while (pfirst != pend)           //外循环
    {                                // pfirst != pend 很有意思
        while (pfirst->next != pend) //内循环
        {
            if (pfirst->val > pfirst->next->val)
            {
                temp = pfirst->val;
                pfirst->val = pfirst->next->val;
                pfirst->next->val = temp;
            }
            pfirst = pfirst->next;
        }
        pend = pfirst; //减少最后的已排好的循环
        pfirst = Head;
    }
    return Head;
}

int main()
{
    node *head;
    head = init();
    creatlist(head);
    head = bubblesort(head);
    printlist(head);
}