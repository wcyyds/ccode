//练习链表
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

void creatList(Node *head)
{
    int val;
    Node *newhead = NULL;
    while (1)
    {
        scanf("%d", &val);
        if (val == -1)
        {
            break;
        }
        newhead = (Node *)malloc(sizeof(Node));
        newhead->val = val;
        newhead->next = head->next;
        head->next = newhead;
    }
}

void printList(Node *head)
{
    Node *p = head->next;
    while (p)
    {
        printf("%d", p->val);
        p = p->next;
    }
}

Node *findList(Node *head) //查，返回的是目标节点的上一个节点
{
    Node *k = head;
    Node *upk = NULL;
    int a;
    scanf("%d", &a);
    while (k != NULL)
    {
        if (a == k->val)
        {
            return upk;
        }
        upk = k;
        k = k->next;
    }
    return NULL;
}

void deleteList(Node *upk) //删
{
    Node *up1k = upk;
    Node *k = up1k->next;
    Node *outk = k->next;
    free(k);
    up1k->next = outk;
}

void increase(Node *upk) //添，给查询链表的前一个查询
{
    Node *newnode = NULL;
    Node *up1k = upk;
    newnode = (Node *)malloc(sizeof(Node));
    int a;
    scanf("%d", &a);
    newnode->val = a;
    newnode->next = up1k->next;
    up1k->next = newnode;
}

void correct(Node *upk)
{
    Node *k = upk->next;
    int a;
    scanf("%d", &a);
    k->val = a;
}

int main()
{
    Node *head = NULL;
    head = init();
    creatList(head);
    printList(head);
    Node *upk = NULL;
    upk = findList(head); //返回的是你要查询的前一个结点
    deleteList(upk);
    increase(upk);
    correct(upk);
    printf("\n\n");
    printList(head);
    return 0;
}