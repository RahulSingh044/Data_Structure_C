#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    int priority;
    struct Node *next;
} Node;

Node *Head = NULL;

// Function to create new Node
Node *newNode(int value, int priority)
{
    Node *newN = (Node *)malloc(sizeof(Node));
    newN->data = value;
    newN->priority = priority;
    newN->next = NULL;
    return newN;
}

void enqueue(int value, int priority)
{
    Node *ptr = newNode(value, priority);
    Node *curr = Head;
    if (curr == NULL)
    {
        Head = ptr;
        return;
    }
    else if (curr->priority > priority)
    {
        ptr->next = curr;
        Head = ptr;
        return;
    }
    while (curr->priority < priority && curr->next != NULL)
    {
        curr = curr->next;
    }
    ptr->next = curr->next;
    curr->next = ptr;
    
}

void dequeue() {
    if(Head == NULL) {
        printf("Queue is underflow or Empty");
        return;
    }
    Node *curr = Head;
    Head = curr->next;
    free(curr);
}

void display()
{
    Node *curr = Head;
    while (curr != NULL)
    {
        printf("%d->", curr->data);
        curr = curr->next;
    }
    printf("NULL");
}

int main()
{
    enqueue(8, 3);
    enqueue(6, 1);
    enqueue(10, 5);
    dequeue();
    display();
}
