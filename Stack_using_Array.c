#include <stdio.h>

#define SIZE 10 
int stack[SIZE];
int top = -1;

void push();
void pop();
void peek();
void display();

int main(){
    int choice, value;
        while(1){
            printf("\n  Stack Operations Menu:\n");
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
                    system("clear");
                    return 0;
                default:
                    printf("Invalid choice, please try again.\n");
            }
        }
}

void push(){
    if(top == SIZE - 1){
        printf("Stack overflow, cannot push mmore elements.\n");
        return;
    }
    int value;
    printf("Enter the value to push onto the stack: ");
    scanf("%d", &value);
    stack[++top] = value;
    printf("Value %d pushed onto the stack.\n", value);
}

void pop(){
    if(top == -1){
        printf("Stack underflow, cannot pop elements.\n");
        return;
    }
    printf("Value %d popped from the stack.\n", stack[top--]);
}

void peek(){
    if(top == -1){
        printf("Stack is empty, nothing to peek.\n");
        return;
    }
    printf("Top value in the stack is: %d\n", stack[top]);
}

void display(){
    if(top == -1){
        printf("Stack is empty, nothing to display.\n");
        return;
    }
    printf("Stack elements are: ");
    for(int i = top; i >= 0; i--){
        printf("%d, ", stack[i]);
    }
}