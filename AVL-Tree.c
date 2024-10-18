#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* right;
    struct Node* left;
    int height;
}AVL;

int getHeight(AVL* node) {
    if(node == NULL) 
        return 0;
    return node->height;
}

AVL* createNode(int val){
    AVL* newNode = (AVL*)malloc(sizeof(AVL));
    newNode->data = val;
    newNode->right = NULL;
    newNode->left = NULL;
    newNode->height = 1;
    
    return newNode;
}

int getBalancingFactor(AVL* node){
    if(node == NULL){
       return 0; 
    }
    
    return getHeight(node->left) - getHeight(node->right);
}

int max(int a , int b) {
    return ( a>b )? a : b;
}

AVL* leftRotate(AVL* x){
    AVL* y = x->right;
    AVL* t2 = y->left;
    
    y->left = x;
    x->right = t2;
    
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    
    return y;
}

AVL* rightRotate(AVL * y) {
    AVL* x = y->left;
    AVL* t2 = x->right;
    
    x->right = y;
    y->left  = t2;
    
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    
    return x;
}

AVL* insertNode(AVL* node, int val){
    if(node == NULL){
        return createNode(val);
    }
    
    if(val < node->data) {
        node->left =  insertNode(node->left, val);
    } else if ( val > node->data ) {
        node->right = insertNode(node->right, val);
    } 
    
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    
    int bf = getBalancingFactor(node);
    
    //Case 1 : Left Left Rotation
        if(bf > 1 && val < node->left->data){
            return rightRotate(node);
        }
    // Case 2 : Right Right Rotation
        if(bf < -1 && val > node->right->data) {
            return leftRotate(node);
        }
    // Case 3 : Left Right Rotation
        if(bf > 1 && val > node->left->data){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    // Case 4 : Right Left Rotation
        if(bf < -1 && val < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        
        return node;

}

void preOrder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
 
int main(){
    AVL* root = NULL;
 
 
    root = insertNode(root, 1);
    root = insertNode(root, 2);
    root = insertNode(root, 4);
    root = insertNode(root, 5);
    root = insertNode(root, 6);
    root = insertNode(root, 3);
    printf("PreOrder Traversal of AVL tree \n");
    preOrder(root);
    return 0;
}
