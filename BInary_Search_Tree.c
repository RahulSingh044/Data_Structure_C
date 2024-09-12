// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>

typedef struct Node{
  int data;
  struct Node *right; 
  struct Node *left;
}Node;

Node *newNode(int val) {
    Node *newN = (Node*)malloc(sizeof(Node));
    newN->data = val;
    newN->left = NULL;
    newN->right = NULL;
    return newN;
}

void inOrderTraversal(Node *rootNode){
    if(rootNode == NULL) return;
    inOrderTraversal(rootNode->left);
    printf("%d\t",rootNode->data);
    inOrderTraversal(rootNode->right);
}

void postOrderTraversal(Node *rootNode){
    if(rootNode == NULL) return;
    inOrderTraversal(rootNode->left);
    inOrderTraversal(rootNode->right);
    printf("%d\t",rootNode->data);
}

void preOrderTraversal(Node *rootNode){
    if(rootNode == NULL) return;
    printf("%d\t",rootNode->data);
    inOrderTraversal(rootNode->left);
    inOrderTraversal(rootNode->right);
   
}

Node  *searchNode(int value,Node *rootNode){
    if(rootNode == NULL || rootNode->data == value){
        return rootNode;
    }
    else if(rootNode->data > value) {
        return searchNode(value,rootNode->left);
    }
    else{
        return searchNode(value,rootNode->right);
    }
    return NULL;
}

int main() {
   Node *root = newNode(12);
    root->left = newNode(10);
    root->right =newNode(20);
    root->left->left = newNode(9);
    root->left->right = newNode(11);
    root->right->left = newNode(19);
    root->right->right = newNode(24);
    printf("In Order Traversal\n");
    inOrderTraversal(root);
    printf("\nIn Post Traversal\n");
    postOrderTraversal(root);
    printf("\nIn Pre Traversal\n");
    preOrderTraversal(root);
    int key = 100;
    printf("\n");
    Node *result = searchNode(key,root);
    if(result==NULL)
       printf("%d is not found",key);
    else
     printf("%d is found ", result->data);
      
}
