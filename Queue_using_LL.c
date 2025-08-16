// Implementation of a Queue in dynamic memory using Linked list in C.

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

void enqueue();
void dequeue();
void display();
void peek();
int isEmpty();

struct node* front = NULL;
struct node* rear = NULL;

int main() {
    int choice;
    while(1) {
        printf("\n Queue Operations Menu:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Check if Empty\n6. Exit\n");
        printf("Enter your choice: ");
        if(scanf("%d", &choice) != 1) {
            printf("Invalid input, please enter an integer.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }
        switch(choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4: 
                peek();
                break;
            case 5:
                if(isEmpty()) {
                    printf("Queue is empty.\n");
                }else{
                    printf("Queue is not empty.\n");
                }
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
                continue;
        }
    }
}

void enqueue() {
    int value;
    printf("Enter the value to enqueue: ");
    scanf("%d", &value);
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }
    newnode->data = value;
    newnode->next = NULL;
    if(rear == NULL) {
        front = rear = newnode;
    }else{
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue() {
    if(isEmpty()){
        printf("Queue is empty, cannot dequeue.\n");
        return;
    }
    struct node* temp = front;
    if(front == rear) {
        printf("Queue is now empty after %d is dequeued.\n", temp->data);
        front = rear = NULL;
    }else{
    front = front->next;
    printf("Dequeued value: %d\n", temp->data);
    }
    free(temp);
}

void display() {
    if(isEmpty()) {
        printf("Queue is empty, nothing to display.\n");
        return;
    }
    struct node* temp = front;
    printf("Queue elements are: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void peek() {
    if(isEmpty()) {
        printf("Queue is empty, nothing to peek.\n");
        return;
    }
    printf("Front value is %d\n", front->data);
}

int isEmpty() {
    if(front == NULL) {
        return 1;
    }else {
        return 0;
    }
}