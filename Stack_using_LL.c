// Implementation of a Stack in dynamic memory using a linked list in C.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* down;
};
struct node* top = NULL;

void push();
void pop();
void peek();
void display();

int main() {
    int choice;
    while(1){
        printf("\n  Stack Operations Menu: \n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                system("cls");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}

void push() {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL){
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }
    printf("Enter the value to push onto the stack:");
    scanf("%d", &newnode->data);
    newnode->down = top;
    top = newnode;
}

void pop() {
    if(top == NULL) {
        printf("Stack underflow, cannot pop elements.\n");
        return;
    }
    struct node* temp = top;
    top = top->down;
    printf("Value %d popped from the stack.\n", temp->data);
    free(temp);
}

void peek() {
    if(top == NULL) {
        printf("Stack is empty, nothing to peek.\n");
        return;
    }
    printf("Top value is %d\n", top->data);
}

void display() {
    if(top == NULL) {
        printf("Stack is empty, nothing to display.\n");
        return;
    }
    struct node* temp = top;
    printf("Stack elements are:");
    while(temp != NULL){
        printf("%d, ", temp->data);
        temp = temp->down;
    }
}