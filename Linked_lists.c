#include <stdio.h>
#include <stdlib.h>
// stores definition of a node in the linked list
struct node {
    int data;
    struct node* next;
};
// function prototypes
void createlist(struct node** head, int* count);
void displaylist(struct node* head);
void insert(struct node** head, int* count);
void insertstart(struct node** head);
void insertend(struct node** head);
void insertmiddle(struct node** head, int* count);
void delete(struct node** head, int* count);
void deletestart(struct node** head);
void deletemiddle(struct node** head, int* count);
void deleteend(struct node** head);
void search(struct node** head);
void reverse(struct node** head);
void deletewhole(struct node** head);
int validinput(int* input);
int main(){
    struct node* head = NULL;
    int choice;
    int count = 0; 
    int i = 0;
    // Main menu loop
    while (i != -1){
    printf("\n1. Create a linked list\n2. Display the linked list\n3. Insert\n4. Delete\n5. Search\n6. Reverse\n7. Delete whole list.\n8. Exit\n\nEnter your choice:");
    if(!validinput(&choice)){
        continue;
    }
    switch (choice)
    {
    case 1:
        createlist(&head, &count);
        printf("%d\n", count);
        break;
    case 2 : 
        displaylist(head);
        break;
    case 3 : 
        insert(&head, &count);
        break;
    case 4:
        delete(&head, &count);
        break;
    case 5:
        search(&head);
        break;
    case 6:
        reverse(&head);
        break;
    case 7:
        deletewhole(&head);
        count = 0; //resets the count after deleting the whole list
        break;
    case 8:
        printf("Exiting the program...\n");
        i = -1;
        break;
    default:
        break;
    }     
    }
        system("clear");
        return 0;
    }  
void createlist(struct node** head, int* count) {
    struct node* newnode = NULL;
    struct node* temp = NULL;
    int num;
    if(*head != NULL) {
        printf("Linked list already exists. Please choose another option.\n");
        return;
    }
    printf("Enter the number of nodes you want to create: ");
    scanf("%d", &num);
    for(int i =0; i < num; i++) {
        newnode = (struct node*) malloc(sizeof(struct node));
        printf("Enter the data for the node %d: ", i+1);
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        (*count)++; // Increments count for each new node
        if(*head == NULL){
            *head = newnode;
            temp = *head;
        }
        else{
            temp->next = newnode;
            temp = newnode;
        }
    }
     printf("Linked List created successfully.\n");
}

void displaylist(struct node* head){
    struct node* temp = head;
    if(head == NULL) {
        printf("The linked list is empty.\n");
        return;
    }
    printf("Current linked list:\n");
    while(temp != NULL){
        printf("%d-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insert(struct node** head, int* count){
    int choice;
    if(*head == NULL){
        printf("The list is empty, create a list first.\n");
        return;
    }
    // Insert menu loop
    while(1){
    printf("Where do you want to insert the node?\n1. At the beginning\n2. At a specific position\n3. At the end\n4. Exit\n\nEnter your choice: ");
    if(!validinput(&choice)){
        continue;
    }
    switch(choice){
        case 1:
            insertstart(head);
            (*count)++;
            return;
        case 2:
            insertmiddle(head, count);
            return;
        case 3:
            insertend(head);
            (*count)++;
            return;
        case 4:
            system("clear");
            return;
        default:
            printf("Invalid choice. Use only the options provided.\n");
            continue;
    } 
}    
}

void insertstart(struct node** head){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data for the new node:");
    scanf("%d", &newnode->data);
    newnode->next = *head;
    *head = newnode;
}

void insertmiddle(struct node** head, int* count){
    int pos;
    struct node* newnode = NULL;
    struct node* temp = *head;
    printf("Enter the position you want to insert the node to:");
    scanf("%d", &pos);
    if(pos > *count){
        printf("Out of bounds\n");
        return;
    }
    for(int i = 1; i < pos-1; i++){
        temp = temp->next;
    }
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data for the node: ");
    scanf("%d", &newnode->data);
    newnode->next = temp->next;
    temp->next = newnode;
    (*count)++;
}

void insertend(struct node** head){
    struct node* temp = *head;
    struct node* newnode = NULL;
    while(temp->next != NULL){
        temp = temp->next;
    }
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data of the new node:");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    temp->next = newnode;
}

void delete(struct node** head, int* count){
     int choice;
    if(*head == NULL){
        printf("The list is empty, create a list first.\n");
        return;
    }
    // Delete menu loop
    while(1){
    printf("Where do you want to delete the node?\n1. At the beginning\n2. At a specific position\n3. At the end\n4. Exit\n\nEnter your choice: ");
    if(!validinput(&choice)){
        continue;
    }
switch(choice){
    case 1:
        deletestart(head);
        (*count)--;
        return;
    case 2:
        deletemiddle(head, count);
        return;
    case 3:
        deleteend(head);
        (*count)--;
        return;
    case 4:
        system("clear");
        return;
    default:
        printf("Enter a valid choice\n");
        continue;
        }
    }
}

void deletestart(struct node** head){
    struct node* temp = *head;
    *head = temp->next;
    free(temp);
}

void deletemiddle(struct node** head, int* count){
    struct node* temp = *head;
    struct node* deletenode = temp;
    int pos;
    printf("Enter the node you want to delete:");
    scanf("%d", &pos);
    if(pos > *count || pos < 1){
        printf("Out of bounds\n");
        return;
    }
    for(int i = 0; i < pos-1; i++){
        temp = temp->next;
    }
    deletenode = temp->next;
    temp->next = deletenode->next;
    free(deletenode);
    (*count)--;
}

void deleteend(struct node** head){
    struct node* temp = *head;
    struct node* deletenode = temp;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    deletenode = temp->next;
    temp->next = NULL;
    free(deletenode);
}

void search(struct node** head){
    if(*head == NULL){
        printf("Please create a list first.\n");
        return;
    }
    struct node* temp = *head;
    int num, i = 0;
    printf("Enter a value to search:");
    scanf("%d", &num);
    while(temp != NULL){
        i++;
        if(temp->data == num){
            printf("%d found at node %d\n", num, i);
            return;
        }
            temp = temp->next;
    }
    printf("%d not found in the list\n", num);
}

void reverse(struct node** head){
    if(*head == NULL){
        printf("Please create a list to reverse it.\n");
        return;
    }
    struct node* temp = *head;
    struct node* prev = NULL;
    struct node* nextn = NULL;
    if(temp->next == NULL){
        printf("The list only contains one element, thus cannot be reversed.\n");
        return;
    }
    while(temp != NULL){
        nextn = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nextn;
    }
    *head = prev;
    printf("The list is now reversed.\n");
}

void deletewhole(struct node** head){
    if(*head == NULL){
        printf("The list is already empty.\n");
        return;
    }
    struct node* temp = *head;
    struct node* prev = NULL;
    while(temp != NULL){
        prev = temp;
        temp = temp->next;
        free(prev);
    }
    *head = NULL;
    printf("The whole list has been deleted.\n");
}

// Function to validate user input for integers
int validinput(int* input) {
    if(scanf("%d", input) != 1) {
        printf("Input only integers. Press enter to continue.\n");
        while(getchar() != '\n' && getchar() != EOF);
        return 0;
    }
    return 1;
}