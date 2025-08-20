#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *create(node* root, int value);
void inorder(node *root);
void preorder(node *root);
void postorder(node *root);
int count(node *root);
void freetree(node *root);

int main()
{
    node *root = NULL;
    int choice, total, value;
    while (1)
    {
        printf("\nBinary Search Tree Menu\n");
        printf("1. Create a Binary Search Tree\n2. In Order Traversal\n3. Pre Order Traversal\n4. Post Order Traversal\n5. Count Nodes\n6. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
            {
                continue;
            }
        }
        switch(choice){
            case 1:
                printf("Enter the value: ");
                scanf("%d", &value);
                root = create(root, value);
                break;
            case 2: 
                if(root == NULL){
                    printf("The tree is empty, please create a tree\n");
                    break;
                }
                inorder(root);
                break;
            case 3: 
                if(root == NULL){
                    printf("The tree is empty, please create a tree\n");
                    break;
                }
                preorder(root);
                break;
            case 4: 
                if(root == NULL){
                    printf("The tree is empty, please create a tree\n");
                    break;
                }
                postorder(root);
                break;
            case 5: 
                if(total == 0){
                    printf("The tree has no nodes, it is empty\n");
                    break;
                }
                total = count(root);
                break;
            case 6: 
                printf("Exiting...");
                freetree(root);
                return 0;
                
        }
    }
}

node* create(node* root, int value){
    node* newnode;
    if(root == NULL){
        newnode = (node*)malloc(sizeof(node));
        newnode->data = value;
        newnode->left = newnode->right = NULL;
        return newnode;
    }

    if(root->data > value){
        root->left = create(root->left, value);
    }
    else if(root->data < value || root->data == value){
        root->right = create(root->right, value);
    }
        
    return root;
}

void inorder(node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(node* root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int count(node* root){
    if(root == NULL){
        return 0;
    }else{
        return 1 + count(root->left) + count(root->right);
    }
}

void freetree(node* root){
    if(root == NULL){
        return;
    }
    freetree(root->left);
    freetree(root->right);
    free(root);
}