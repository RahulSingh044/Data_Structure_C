#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

// initializing Head Node
Node *Head = NULL;

// function for creating  Node
Node *newNode(int value)
{
    struct Node *newN = (Node *)malloc(sizeof(Node));
    newN->data = value;
    newN->next = NULL;
    newN->prev = NULL;
    return newN;
}

// Insertion at begning of Linked List
void insertBeg(int value)
{
    Node *newN = newNode(value);
    if (Head == NULL)
    {
        Head = newN;
        return;
    }
    newN->next = Head;
    Head = newN;
}

// Insertion at the end of the Linked list
void insertEnd(int value)
{
    Node *newN = newNode(value);
    Node *curr = Head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = newN;
    newN->prev = curr;
}

void delete(int key)
{
    Node *curr = Head;
    Node *ptr = Head->next;
    
    if (curr->data == key)
    {
        curr->next->prev = NULL;
        Head = ptr;
        free(curr);
        return;
    }

    while (ptr->data != key && ptr->next != NULL)
    {
        ptr = ptr->next;
        curr = curr->next;
    }
    curr->next = ptr->next;
    if (ptr->next != NULL)
    {
        ptr->next->prev = curr;
    }
    free(ptr);
}

void display()
{
    Node *curr = Head;
    while (curr != NULL)
    {
        printf("%d->", curr->data);
        curr = curr->next;
    }
    printf("Null");
}

int main()
{
    insertBeg(20);
    insertBeg(80);
    insertBeg(90);
    insertEnd(33);
    delete (90);
    display();
}
