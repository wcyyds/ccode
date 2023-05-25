#include<stdio.h>
#include<stdlib.h>

typedef struct Node1234
{
    /* data */
    int data;
    struct node *next;
    
}node;

node *init()
{
    node *head;
    head = (node*)malloc(sizeof(node));
    head->next = NULL;
    return head;    
}

void creatList(node *head){
    int val;
    node *p = head;
    node *q = NULL;
    while(1){
        scanf("%d",&val);
        if(val == -1){
            break;
        }
        q = (node*)malloc(sizeof(node));
        q->data = val;
        p->next = q;
        p = p->next;
    }
    p->next = NULL;
}

void prinfList(node  *head){
    node *p = head;
    p = p->next;
    while(p){
        printf("%d ", p->data);
        p = p->next;
    }
}

int main(){
    node *head;
    head = init();
    creatList(head);
    prinfList(head);
    return 0;
}