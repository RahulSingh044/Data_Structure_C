#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}QNode;

QNode *f = NULL;
QNode *r = NULL;

void enqueue(int val) {
    QNode *q = (QNode*)malloc(sizeof(QNode));
    if(q==NULL) {
        printf("Queue is full");
        return;
    }
    else {
        q->data = val;
        q->next = NULL;
        if(f==NULL) {
            f=r=q;
        }
        else {
            r->next = q;
            r = q;
        }
    }
}

void dequeue() {
    if(f==NULL) {
        printf("Queue is Empty");
        return;
    }
    else {
        QNode *curr = f;
        f = f->next;
        free(curr);
        if(f==r) {
            f = r = NULL;
        }
    }
}

void display() {
    QNode *curr = f;
    while(curr!=NULL) {
        printf("%d->",curr->data);
        curr = curr->next;
    }
}
int main() {
    enqueue(5);
    enqueue(88);
    enqueue(10);
    dequeue();
    display();
}
