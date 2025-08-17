// Basic Implementation of Binary Tree with In-Order, Pre-Order, and Post-Order Traversal.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *create();
void inorder(node *root);
void preorder(node *root);
void postorder(node *root);
int count(node *root);
void freeTree(node *root);

int main()
{
    node *root = NULL;
    int choice, total;
    while (1)
    {
        printf("\nBinary Tree Operations Menu:\n");
        printf("1. Create Tree\n2. Display In-Order\n3. Display Pre-Order\n4. Display Post-Order\n5. Count the nodes\n6. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input, please enter an integer.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            continue;
        }
        switch (choice)
        {
        case 1:
            root = create();
            break;
        case 2:
            if (root == NULL)
            {
                printf("Tree is empty, please create a tree first.\n");
                break;
            }
            inorder(root);
            break;
        case 3:
            if (root == NULL)
            {
                printf("Tree is empty, please create a tree first.\n");
                break;
            }
            preorder(root);
            break;
        case 4:
            if (root == NULL)
            {
                printf("Tree is empty, please create a tree first.\n");
                break;
            }
            postorder(root);
            break;
        case 5:
            total = count(root);
            if (total == 0)
            {
                printf("Tree is empty, so the total nodes are 0.\n");
            }
            else
            {
                printf("The number of nodes in the tree is: %d\n", total);
            }
            break;
        case 6:
            printf("Exiting...");
            freeTree(root);
            return 0;
        default:
            printf("Please enter a valid choice\n");
            break;
        }
    }
}

node *create()
{
    int value;
    printf("Enter the value you want to enter (enter -1 for no node): ");
    scanf("%d", &value);
    if (value == -1)
    {
        return NULL;
    }
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = value;
    printf("Enter the left child of %d :\n", newnode->data);
    newnode->left = create();
    printf("Enter the right child of %d :\n", newnode->data);
    newnode->right = create();
    return newnode;
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int count(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + count(root->left) + count(root->right);
    }
}

void freeTree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}