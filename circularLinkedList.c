#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *Head = NULL;

//Function to create a new node
struct Node *newNode(int value)
{
    struct Node *newN = (struct Node *)malloc(sizeof(struct Node));
    newN->data = value;
    newN->next = newN;
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

void insertAtPosition(int value, int position){
    if(position <= 0){
        printf("Invalid position\n");
        return;
    }
    struct Node *nodeptr = newNode(value);
    if(position == 1){
        insertAtBeg(value);
        return;
    }
    struct Node *current = Head;
    for(int i = 1; i < position - 1; i++){
        if(current == Head){
            printf("Invalid position\n");
            return;
        }
        current = current->next;
    }
    nodeptr->next = current->next;
    current->next = nodeptr;
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
    while (current->next != Head)
    {
        current = current->next;
    }
    current->next = nodeptr;
    nodeptr->next = Head;
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
    while (ptr->data != value && ptr->next != Head)
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
    do
    {
        if (current->data == value)
        {
            printf("Element %d found in the list at %d\n", value,i);
            return;
        }
        current = current->next;
        i++;
    }while (current != Head);
    printf("Element %d not found in the list\n", value);
}

void printlist()
{
    struct Node *curr = Head;
    do{
         printf("%d->\t", curr->data);
        curr = curr->next;
    }while (curr != Head);
    
}

int main()
{
    insertAtBeg(88);
    insertAtEnd(99);
    insertAtPosition(77, 2);
    // delete (77);
    search(99);
    printlist();
    return 0;
}
