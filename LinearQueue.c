#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 // Define the maximum size of the queue

int queue_array[MAX_SIZE];
int front = -1;
int rear = -1;

// Function prototypes
void enqueue(int data);
void dequeue();
void display();
int isEmpty();
int isFull();

int main() {
    int choice, value;

    while (1) {
        printf("\n---- Linear Queue Menu ----\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input.\n");
                    while (getchar() != '\n');
                    break;
                }
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// Check if the queue is empty
int isEmpty() {
    if (front == -1 || front > rear)
        return 1;
    else
        return 0;
}

// Check if the queue is full
int isFull() {
    if (rear == MAX_SIZE - 1)
        return 1;
    else
        return 0;
}

// Function to add an element to the queue (Enqueue)
void enqueue(int data) {
    if (isFull()) {
        printf("Queue Overflow: Cannot add more elements, the queue is full.\n");
    } else {
        if (front == -1)
            front = 0; // Set front to 0 when the first element is inserted
        rear++;
        queue_array[rear] = data;
        printf("Inserted %d into the queue.\n", data);
    }
}

// Function to remove an element from the queue (Dequeue)
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow: Cannot delete elements, the queue is empty.\n");
    } else {
        printf("Deleted element: %d\n", queue_array[front]);
        if (front >= rear) {
            // Queue becomes empty after this deletion, reset front and rear
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }
}

// Function to display the elements of the queue
void display() {
    int i;
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (i = front; i <= rear; i++) {
            printf("%d ", queue_array[i]);
        }
        printf("\n");
    }
}