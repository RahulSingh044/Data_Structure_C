#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

Node *Head = NULL;

struct Node *newNode(int value)
{
    struct Node *newN = (struct Node *)malloc(sizeof(struct Node));
    newN->data = value;
    newN->next = NULL;
    return newN;
}

void insertAtBeg(int value)
{
    struct Node *nodeptr = newNode(value);
    if (Head == NULL)
    {
        Head = nodeptr;
        return;
    }
    nodeptr->data = value;
    nodeptr->next = Head;
    Head = nodeptr;
}

void insertAtPos(int value, int indx)
{
    Node *newN = newNode(value);
    Node *curr = Head;
    int i = 0;
    // if you are inserting node at head
    if(indx == 0) {
        insertAtBeg(value);
        return;
    }
    while (i != indx-1 && curr != NULL)
    {
        curr = curr->next;
        i++;
    }
    newN->next = curr->next;
    curr->next = newN;
}

void insertAtEnd(int value)
{
    struct Node *nodeptr = newNode(value);
    if (Head == NULL)
    {
        Head = nodeptr;
        return;
    }
    struct Node *current = Head;
    nodeptr->data = value;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = nodeptr;
    nodeptr->next = NULL;
}

void delete(int value)
{
    struct Node *curr = Head;
    struct Node *ptr = Head->next;
    if (Head->data == value)
    {
        Head = ptr;
        free(curr);
        return;
    }
    while (ptr->data != value && ptr->next != NULL)
    {
        curr = curr->next;
        ptr = ptr->next;
    }
    curr->next = ptr->next;
    if (ptr->data == value)
    {
        free(ptr);
    }
    else
        printf("The element is not present in the linked list");
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
    printf("Element not found in the list: %d\n", value);
}

void printlist()
{
    struct Node *curr = Head;
    while (curr != NULL)
    {
        printf("%d->\t", curr->data);
        curr = curr->next;
    }
    printf("NULL");
}

int main()
{
    insertAtBeg(88);
    insertAtPos(77,1);
    insertAtEnd(99);
    // delete (65);
    search(65);
    printlist();
    return 0;
}
