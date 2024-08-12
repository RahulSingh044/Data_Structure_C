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

// Insert at particular position
void insertAtPos(int value, int indx)
{
    Node *newN = newNode(value);
    Node *curr = Head;
    int i = 0;
    // if you are inserting node at head
    if(indx == 0) {
        insertBeg(value);
        return;
    }
    while (i != indx-1 && curr != NULL)
    {
        curr = curr->next;
        i++;
    }
    curr->next->prev = newN;
    newN->next = curr->next;
    curr->next = newN;
    newN->prev = curr;

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

void reverse()
{
    Node *curr = Head;
    Node *prev = NULL;
    Node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    }
    Head = prev;
    printf("Reverse Linked List: \n");
    display();
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

void search(int value)
{
    struct Node *current = Head;
    int i=0;
   while (current != NULL)
    {
        if (current->data == value)
        {
            printf("Element %d found in the list at %d\n", value,i);
            return;
        }
        current = current->next;
        i++;
    }
    printf("Element %d not found in the list\n", value);
}

int main()
{
    insertBeg(20);
    insertBeg(80);
    insertBeg(90);
    insertAtPos(151, 0);
    insertEnd(33);
    display();
    reverse();
}
