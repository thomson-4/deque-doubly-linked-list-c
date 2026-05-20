#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
typedef struct Node 
{
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Dequeue structure
typedef struct Dequeue
{
    Node* front;
    Node* rear;
} Dequeue;

// Function to create an empty dequeue
Dequeue* initialize() 
{
    Dequeue* dequeue = (Dequeue*)malloc(sizeof(Dequeue));
    dequeue->front = NULL;
    dequeue->rear = NULL;
    return dequeue;
}

// Function to check if the dequeue is empty
int isEmpty(Dequeue* dequeue) {
    return dequeue->front == NULL;
}

// Function to insert an element at the front
void insertFront(Dequeue* dequeue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = dequeue->front;

    if (isEmpty(dequeue)) {
        dequeue->rear = newNode;
    } else {
        dequeue->front->prev = newNode;
    }
    dequeue->front = newNode;
    printf("Inserted %d at the front.\n", data);
}

// Function to insert an element at the rear
void insertRear(Dequeue* dequeue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = dequeue->rear;

    if (isEmpty(dequeue)) {
        dequeue->front = newNode;
    } else {
        dequeue->rear->next = newNode;
    }
    dequeue->rear = newNode;
    printf("Inserted %d at the rear.\n", data);
}

// Function to delete an element from the front
int deleteFront(Dequeue* dequeue) {
    if (isEmpty(dequeue)) {
        printf("Dequeue is empty! Cannot delete from front.\n");
        return -1;
    }

    Node* temp = dequeue->front;
    int data = temp->data;
    dequeue->front = temp->next;

    if (dequeue->front == NULL) {
        dequeue->rear = NULL;
    } else {
        dequeue->front->prev = NULL;
    }
    free(temp);
    printf("Deleted %d from the front.\n", data);
    return data;
}

// Function to delete an element from the rear
int deleteRear(Dequeue* dequeue) {
    if (isEmpty(dequeue)) {
        printf("Dequeue is empty! Cannot delete from rear.\n");
        return -1;
    }

    Node* temp = dequeue->rear;
    int data = temp->data;
    dequeue->rear = temp->prev;

    if (dequeue->rear == NULL) {
        dequeue->front = NULL;
    } else {
        dequeue->rear->next = NULL;
    }
    free(temp);
    printf("Deleted %d from the rear.\n", data);
    return data;
}

// Function to display the contents of the dequeue
void display(Dequeue* dequeue) {
    if (isEmpty(dequeue)) {
        printf("Dequeue is empty.\n");
        return;
    }

    printf("Dequeue contents: ");
    Node* current = dequeue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function for testing the dequeue
int main() {
    Dequeue* dequeue = initialize();
    int choice, value;
    printf("\nMenu:\n");
    printf("1. Insert Front\n");
    printf("2. Insert Rear\n");
    printf("3. Delete Front\n");
    printf("4. Delete Rear\n");
    printf("5. Display Dequeue\n");
    printf("6. Exit\n");
    while (1) 
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
        case 1:
            printf("Enter value to insert at front: ");
            scanf("%d", &value);
            insertFront(dequeue, value);
            printf("\n");
            break;
        case 2:
            printf("Enter value to insert at rear: ");
            scanf("%d", &value);
            insertRear(dequeue, value);
            printf("\n");
            break;
        case 3:
            deleteFront(dequeue);
            printf("\n");
            break;
        case 4:
            deleteRear(dequeue);
            printf("\n");
            break;
        case 5:
            display(dequeue);
            printf("\n");
            break;
        case 6:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
}
