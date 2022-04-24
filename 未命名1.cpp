#include<stdio.h>
#include<stdlib.h>

typedef struct node {
   int val;
   struct node *next;
}Node;

Node *init () {
    Node *head;
    head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    return head;
}

void creatTail(Node *head) {
    int val;
    Node *p = head;
    Node *q = NULL;
    while (1) {
        scanf("%d", &val);
        if (val == -1) {
        	break;
		}
        q = (Node*)malloc(sizeof(Node));
        q->val = val;
        p->next = q;
        p = p->next;
    }
    p->next = NULL;
}

void printList(Node *head) {
    Node *p = head->next;
    while(p) {
        printf("%d", p->val);
        p = p->next;
    }
}

int main() {
    Node *head;
    head = init();
    creatTail(head);
    printList(head);
    return 0;
}
