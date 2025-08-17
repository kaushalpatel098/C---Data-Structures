// Implementation of a Double Endedd Queue (Deque) using Array

#include <stdio.h>

#define MAX 5 

int deque[MAX];
int front = -1, rear = -1;

void insertfront();
void insertrear();
void deletefront();
void deleterear();
void display();
int isEmpty();
int isFull();

int main(){
    int choice;
    while(1){
        printf("\n Deque Operations Menu:\n");
        printf("1. Insert at Front\n2. Insert at Rear\n3. Delete from Front\n4. Delete from Rear\n5. Display\n6. Check if Empty\n7. Check if Full\n8. Exit\n");
        printf("Enter your choice: ");
        if(scanf("%d", &choice) != 1){
            printf("Invalid input, please enter an integer.\n");
            int c;
            while((c = getchar()) != '\n' && c != EOF);
            continue;
        }
            switch(choice){
                case 1:
                    insertfront();
                    break;
                case 2:
                    insertrear();
                    break;
                case 3:
                    deletefront();
                    break;
                case 4: 
                    deleterear();
                    break;
                case 5: 
                    display();
                    break;
                case 6:
                    if(isEmpty()){
                        printf("Deque is empty.\n");
                        break;
                    }
                        printf("Deque is not empty.\n");
                        break;
                case 7:
                    if(isFull()){
                        printf("Deque is full.\n");
                        break;
                    }
                    printf("Deque is not full.\n");
                    break;
                case 8:
                    printf("Exiting...\n");
                    return 0;
                default:
                    printf("Invalid choice, please try again.\n");
        }
    }
}

void insertfront(){
    if(isFull()){
        printf("Deque is full, cannot insert at front.\n");
        return;
    }
    int value;
    printf("Enter the value to insert at front: ");
    scanf("%d", &value);
    if(isEmpty()){
        front = rear = 0;
        deque[front] = value;    
    }else{
        front = (front - 1 + MAX) % MAX;
        deque[front] = value;
    }
}

void insertrear(){
    if(isFull()){
        printf("Deque is full, cannot insert at rear.\n");
        return;
    }
    int value;
    printf("Enter the value to insert at rear: ");
    scanf("%d", &value);
    if(isEmpty()){
        front = rear = 0;
        deque[rear] = value;
    }else{
        rear = (rear + 1) % MAX;
        deque[rear] = value;
    }
}

void deletefront(){
    if(isEmpty()){
        printf("Deque is empty, cannot delete from front.\n");
        return;
    }
    int value = deque[front];
    if(front == rear){
        front = rear = -1;
        printf("Deque is now empty after deleteing %d from front.\n", value);
    }else{
        front = (front + 1) % MAX;
        printf("Deleted %d from front.\n", value);
    }
}

void deleterear(){
    if(isEmpty()){
        printf("Deque is empty, cannot delete from rear.\n");
        return;
    }
    int value = deque[rear];
    if(front == rear){
        front = rear = -1;
        printf("Deque is now empty after deleting %d from rear.\n", value);
    }else{
        rear = (rear - 1 + MAX) % MAX;
        printf("Deleted %d from rear.\n", value);
    }
}

void display(){
    if(isEmpty()){
        printf("Deque is empty, nothing to display.\n");
        return;
    }
    printf("Deque elements: ");
    int i = front;
    while(i != rear){
        printf("%d ", deque[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", deque[rear]);
}

int isEmpty(){
    return (front == -1);
}

int isFull(){
    return ((rear + 1) % MAX == front);
}

