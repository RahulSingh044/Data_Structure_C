#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
} tree;

tree *root = NULL;

tree *newNode(int data)
{
    tree *node = (tree *)malloc(sizeof(tree));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

tree *insertIntoBST(tree *root, int data)
{
    if (root == NULL)
    {
        root = newNode(data);
        return root;
    }

    if (data < root->data)
        root->left = insertIntoBST(root->left, data);
    else
        root->right = insertIntoBST(root->right, data);

    return root;
}

void takeInput()
{
    int data;
    scanf("%d", &data);

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        scanf("%d", &data);
    }
}

void inorderTraversal(tree *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Searching Node In BST
bool nodeSearch(tree *root, int data)
{
    // base case
    if (root == NULL)
        return false;

    if (root->data == data)
        return true;

    if (data < root->data)
    {
        return nodeSearch(root->left, data);
    }
    else
    {
        return nodeSearch(root->right, data);
    }
}

// Minimum node in BST
int minNode(tree *root)
{
    tree *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}

// Maximum node in BST
int maxNode(tree *root)
{
    tree *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}

// Delete node from BST
tree *deleteNode(tree *root, int val)
{

    // base case
    if (root == NULL)
        return root;

    if (root->data == val)
    {

        // having 0 child
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        // having 1 child
        // left child
        if (root->left != NULL && root->right == NULL)
        {
            tree *temp = root;
            free(root);
            return temp;
        }

        // right child
        if (root->left == NULL && root->right != NULL)
        {
            tree *temp = root;
            free(root);
            return temp;
        }

        // having 2 child with minimum value approach
        if (root->left != NULL && root->right != NULL)
        {
            int minVal = minNode(root->right);
            root->data = minVal;
            root->right = deleteNode(root->right, minVal);
            return root;
        }
    }
    else if (val < root->data)
    {
        root->left = deleteNode(root->left, val);
        return root;
    }
    else
    {
        root->right = deleteNode(root->right, val);
        return root;
    }
}

int main()
{

    printf("Enter data to create a BST \n");
    takeInput();

    printf("Inorder traversal of the BST: ");
    inorderTraversal(root);

    int searchData;
    printf("\nEnter the number to search: ");
    scanf("%d", &searchData);
    int result = nodeSearch(root, searchData);

    if (result)
    {
        printf("%d found in the BST\n", searchData);
    }
    else
    {
        printf("%d not found in the BST\n", searchData);
    }

    printf("Enter the number to delete: ");
    scanf("%d", &searchData);
    root = deleteNode(root, searchData);

    printf("Inorder traversal of the BST: ");
    inorderTraversal(root);
}
