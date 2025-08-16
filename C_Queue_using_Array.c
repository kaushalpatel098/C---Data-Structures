// Circular Queue Implementation using Array. 


#include <stdio.h>

#define MAX 5 

int queue[MAX];
int front = -1, rear = -1;

void enqueue();
void dequeue();
void display();
void peek();
int isEmpty();
int isFull();

int main() {
    printf("Queue Operations Menu:\n");
    int choice;
    while(1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Check if Empty\n6. Check if Full\n7. Exit\n");
        printf("Enter your choice: ");
        // scanf("%d", &choice);
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
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 6:
                if(isFull()) {
                    printf("Queue is full.\n");
                } else {
                    printf("Queue is not full.\n");
                }
                break;
            case 7:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
                continue;
        }
    }
}

void enqueue() {
    if(isFull()){
        printf("Queue is full, cannot enqueue.\n");
        return;
    }else{
        int value;
        printf("Enter the value to enqueue: ");
        scanf("%d", &value);
        if(front == -1) {
            front = 0;
        }
        rear = (rear + 1) % MAX;
        queue[rear] = value;
        printf("Enqueued value: %d\n", value);
    }
}

void dequeue() {
    if(isEmpty()) {
        printf("Queue is empty, cannot dequeue.\n");
        }
        else if(front == rear && front != -1) {
            printf("Dequeued value: %d\n", queue[front]);
            front = rear = -1;
            printf("Queue is now empty after dequeue.\n");
        } else{
            int value = queue[front];
            front = (front + 1) % MAX;
            printf("Dequeued value: %d\n", value);
            return;
        }
    }

void display() {
    if(isEmpty()) {
        printf("Queue is empty, nothing to display.\n");
    }else{
        printf("Queue elements: ");
        int temp = front;
        while(temp != rear) {
            printf("%d ", queue[temp]);
            temp = (temp + 1) % MAX;
        }
        printf("%d\n", queue[rear]);
    }
}

void peek() {
    if(isEmpty()) {
       printf("Queue is empty, nothing to peek.\n");
    }else{
      printf("Front element: %d\n", queue[front]);

    }
}

int isEmpty() {
    if(front == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull() {
    if((rear + 1) % MAX == front) {
        return 1;
    }
    else{ 
        return 0;
    }
}