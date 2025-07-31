#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void createarray(int** arr, int* size);
void printarray(int* arr, int size);
void insertarray(int** arr, int* size);
int insertstart(int** arr, int size);
int insertmiddle(int** arr, int size);
int insertend(int** arr, int size);
void deletearray(int** arr, int* size);
int deletefirst(int** arr, int size);
int deletemiddle(int** arr, int size);
int deleteend(int** arr, int size);
int deletewhole(int** arr);
void search(int* arr, int size);
void reverse(int** arr, int size);
void bubblesort(int* arr, int size);
int validinput(int* input);

int main(){
    int* arr = NULL;
    int size, choice;
    int flag = 0;
    //Main menu loop
    while(flag != -1){
        printf("\n1. Create an Array.\n2. Display the array.\n3. Insert\n4. Delete\n5. Search\n6. Reverse\n7. Sort the array\n8. Exit\n\nEnter your choice:");
        if(!validinput(&choice)){
        continue;
    }
        switch(choice){
            case 1: 
                createarray(&arr, &size);
                break;
            case 2: 
                printarray(arr, size);
                break;
            case 3:
                insertarray(&arr, &size);
                break;
            case 4:
                deletearray(&arr, &size);
                break;
            case 5:
                search(arr, size);
                break;
            case 6:
                reverse(&arr, size);
                break;
            case 7:
                bubblesort(arr, size);
                break;
            case 8:
                printf("Exiting..");
                flag = -1;
                break;
            default:
                printf("Invalid choice, please try again.\n");
                continue;
        }

    }
    system("clear");
    return 0;
}

void createarray(int** arr, int* size) {
    printf("Enter the size of the array: ");
    scanf("%d", size);
    *arr = (int*)malloc((*size) * sizeof(int));
    for(int i = 0; i < (*size); i++){
        printf("Enter the %d element of the array:", i+1);
        scanf("%d", &(*arr)[i]);
    }
    printf("Array created successfully\n");
}

void printarray(int* arr, int size){
    if(arr == NULL){
        printf("The array is empty, please create an array first\n");
        return;
    }
    printf("The array is :\n");
    for(int i = 0; i < size; i++){
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

void insertarray(int** arr, int* size){
    system("clear");
    int choice;
    //Check if the array is empty
    if(*arr == NULL){
        printf("The array is empty, please create an array first.\n");
        return;
    }
    while(1){
    printf("\nWhere do you want to insert :\n\n1. At the beginning\n2. At specific index\n3. At the end\n4. Exit\n\nEnter your choice:");
    if(!validinput(&choice)){
        continue;
    }

    switch(choice){
        case 1:
           if(insertstart(arr, *size) == 0){
                (*size)++;
           }
            break;
        case 2:
            if(insertmiddle(arr, *size) == 0){
                (*size)++;
            }
            break;
        case 3:
            if(insertend(arr, *size) == 0 ){
                (*size)++;
            }else{
                fprintf(stderr, "Memory allocation failed.\n");
            }
            break;
        case 4:
            system("clear");
            return;
    }
 } 
}

int insertstart(int** arr, int size){
    int val;
    printf("Enter the value you want to enter:");
    scanf("%d", &val);
    int* temp = realloc(*arr, (size+1)*sizeof(int)); // Allocate memory for the new array
    if(temp != NULL){   // Check if memory allocation was successful
        *arr = temp;
    }
    else{
        printf("No memory allocated, please try again.\n");
        return -1;
    }
    for(int i = size; i > 0; i--){
        (*arr)[i] = (*arr)[i-1];
    }
    (*arr)[0] = val;
    printf("Value inserted at the beginning successfully.\n");
    return 0;
}

int insertmiddle(int** arr, int size){
    int val, index;
    printf("Enter the index at which you want to enter the value:");
    scanf("%d", &index);
    if(index >= size || index < 0){        //Check if the index provided is valid
        printf("Out of bound index. Please try again.\n");
        return -1;
    }
    printf("Enter the value:");
    scanf("%d", &val);
    int* temp = realloc(*arr, (size+1)* sizeof(int));
    if(temp != NULL){
        *arr = temp;
    }
    else{
        printf("No memory allocated, please try again.\n");
        return -1;
    }
    for(int i = size; i > index; i--){
        (*arr)[i] = (*arr)[i-1];
    }
    (*arr)[index] = val;
    printf("%d added at %d index\n", val, index);
    return 0;
}

int insertend(int** arr, int size){
    int val;
    printf("Enter the value you want to insert:");
    scanf("%d", &val);
    int* temp = realloc(*arr, (size+1)* sizeof(int));
    if(temp != NULL){
        *arr = temp;
    }
    else{
        printf("No memory allocated, please try again.\n");
        return -1;
    }
    (*arr)[size] = val;
    printf("%d entered at the end successfully.\n", val);
    return 0;
}

void deletearray(int** arr, int* size){
    if(*arr == NULL){
        printf("The array is empty, please create an array first.\n");
        return;
    }
     if(*size == 1){
        int choice;
        printf("The array only has one element, do you want to delete the whole array?:\n1. Yes\n2. No(return to the menu.)\nYour choice:");
        scanf("%d", &choice);
        if(choice == 1){
            free(*arr);
            *arr = NULL;
            *size = 0;
            printf("Array deleted successfully.\n");
            return;
        }else if(choice == 2){
                printf("Array not deleted, returning to main menu.\n");
                return;
        }else{
            printf("Invalid choice, array not deleted and returning to the main menu.\n");
            return;
        }
        
    }
    int choice;
    while(1){
        printf("Where do you want to delete:\n1. At the beginning\n2. At a specific index\n3. At the end\n4. Delete whole array\n5. Exit\n\nEnter your choice:");
    if(!validinput(&choice)){
        continue;
    }
    switch(choice){
        case 1:
            if(deletefirst(arr, *size) == 0){
                (*size)--;   //update the size after successful function call
            }
            break;
        case 2:
            if(deletemiddle(arr, *size) == 0){
                (*size)--;
            }
            break;
        case 3:
            if(deleteend(arr, *size) == 0){
                (*size)--;
            }
            break;
        case 4:
            if(deletewhole(arr) == 0){
                (*size) = 0;
            }
            break;
        case 5:
            system("clear");
            return;
    }
    }
}

int deletefirst(int** arr, int size){
    for(int i = 1; i < size; i++){
        (*arr)[i-1] = (*arr)[i];
    }
    int* temp = realloc(*arr, (size - 1)*sizeof(int));
    if(temp != NULL){
        *arr = temp;
        printf("First element successfully deleted..\n");
        return 0;
    }else{
        fprintf(stderr, "Encountered an error\n");
        return -1;
    }
}

int deletemiddle(int** arr, int size){
    int index, poped;
    printf("Enter the index at which the value you want to delete:");
    scanf("%d", &index);
    if(index >= size || index < 0){
        printf("Out of bound index\n");
        return -1;
    }
    poped = (*arr)[index];
    for(int i = index+1; i < size; i++){
        (*arr)[i-1] = (*arr)[i];
    }
    int* temp = realloc(*arr, (size-1) * sizeof(int));
    if(temp != NULL){
        *arr = temp;
        printf("Successfully deleted %d at %d index\n", poped, index);
        return 0;
    }else{
        fprintf(stderr, "Encountered an error\n");
        return -1;
    }
}

int deleteend(int** arr, int size){
    int poped = (*arr)[size-1];
    int* temp = realloc(*arr, (size-1)*sizeof(int));
    if(temp != NULL){
        *arr = temp;
        printf("Deleted %d from the array.\n", poped);
        return 0;
    }else{
        fprintf(stderr, "Encountered an error\n");
        return -1;
    }
}

int deletewhole(int** arr){
    free(*arr);
    *arr = NULL;
    printf("Deleted the whole array.\n");
    return 0;
}

void search(int* arr, int size){            // Function for linear search in the array
    if(arr == NULL){
        printf("The array is empty, please create an array first.\n");
        return;
    }
    int val;
    printf("Enter the value you want to search for: ");
    scanf("%d", &val);
    for(int i =0; i < size; i++){
        if(arr[i] == val){
            printf("value %d found at index %d\n", val, i);
            return;
        }
    }
    printf("Value %d not found in the array.\n", val);
}

void reverse(int** arr, int size) {
    if(*arr == NULL){
        printf("The array is empty, please create an array first.\n");
        return;
    }
    if(size == 1){
        printf("The array has only one element, reversing is not needed.\n");
        return;
    }
    int* temp;
    temp = (int*)malloc(size * sizeof(int));
    if(temp == NULL){
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }
    for(int i = 0; i < size; i++){
        temp[i] = (*arr)[(size -1) - i];
    }
    free(*arr);
    *arr = temp;
    printf("Array reversed successfully.\n");    
}

void bubblesort(int* arr, int size){            // Function to sort the array using bubble sort
    if(arr == NULL || size == 0){
        printf("Array is empty, cannot sort.\n");
        return;
    }

    int temp;
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Array sorted using bubble sort.\n");
}

int validinput(int* input) {             //Function to validate user input for integers
    if(scanf("%d", input) != 1) {
        printf("Input only integers. Press enter to continue.\n");
        while(getchar() != '\n' && getchar() != EOF);
        return 0;
    }
    return 1;
}