#include<stdio.h>
#include<stdlib.h>

// TREE
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Tree;

//Queue
typedef struct queue {
    int front, rear;
    int size;
    struct Node** array;
}Queue;

// Function to create a queue
 Queue* createQueue(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = 0;
    queue->size = size;
    queue->array = (struct Node**)malloc(queue->size * sizeof(struct Node*));
    return queue;
}

// Function to check if the queue is empty
int isEmpty( Queue* queue) {
    return queue->front == queue->rear;
}

// Function to add an element to the queue
void enqueue(Queue* queue, struct Node* node) {
    queue->array[queue->rear++] = node;
}

// Function to remove an element from the queue
struct Node* dequeue(Queue* queue) {
    return queue->array[queue->front++];
}

// Function to create a new node
Tree* newNode(int data) {
    Tree *newN = (Tree*) malloc(sizeof(Tree));
    newN->data = data;
    newN->left = NULL;
    newN->right = NULL;
    return newN;
}

//Function to create a TREE
Tree* newTree(Tree *root) {

    printf("Enter the data \t");
    int data;
    scanf("%d",&data);
    root = newNode(data);

    if(root->data == -1){
        return NULL;
    }

    printf("Enter data to left of %d\n", root->data);
    root->left = newTree(root->left);

    printf("Enter data to right of %d\n", root->data);
    root->right = newTree(root->right);

    return root;
}

//Level Order Traversal Functions
void levelOrderTraversal(Tree *root) { 
    if(root == NULL) 
     return;

    Queue* queue = createQueue(100);
    enqueue(queue, root);

    while(!isEmpty(queue)){
        Tree* temp = dequeue(queue);
        printf("%d ", temp->data);

        if(temp->left) {
            enqueue(queue, temp->left);
        }

        if(temp->right) {
            enqueue(queue, temp->right);
        }
    }

    printf("\n");
}

//Inorder Traversal Functions
void inOrderTraversal(Tree *root) {

    if(root == NULL)
     return;

    inOrderTraversal(root->left);
    printf("%d \t", root->data);
    inOrderTraversal(root->right);

}

//Preorder Traversal Functions
void preOrderTraversal(Tree *root) {
    if(root == NULL)
     return;

    printf("%d \t",root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

//Postorder Traversal Functions
void postOrderTraversal(Tree *root) {
    if(root == NULL)
     return;

     postOrderTraversal(root->left);
     postOrderTraversal(root->right);
     printf("%d \t", root->data);
}

int main() {
    Tree * root = (Tree*) malloc(sizeof(Tree));
    printf("Note: Enter -1 for inserting NULL values into the tree \n");
    root = newTree(root);
    printf("Level Order Traversal: ");
    levelOrderTraversal(root);
    printf("\nInorder Traversal: ");
    inOrderTraversal(root);
    printf("\nPreorder Traversal: ");
    preOrderTraversal(root);
    printf("\nPostorder Traversal: ");
    postOrderTraversal(root);
    return 0;
}

