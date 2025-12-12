#include <stdio.h>
#define SIZE 5     // max elements we can store

int queue[SIZE];   // array to hold our queue elements
int front = -1;    // tracks where to remove from
int rear = -1;     // tracks where to add to
                   // both start at -1 = empty queue

// Check if queue is full
// Two ways it can be full:
// 1. front at start (0) and rear at end (SIZE-1)
// 2. rear is right behind front (wrapped around)
int isFull() {
    return (front == 0 && rear == SIZE - 1) || (rear + 1 == front);
}
`
// Check if empty - just see if front is still -1
int isEmpty() {
    return front == -1;
}

// Insert element at rear
// Important: Use (rear + 1) % SIZE to wrap around!
// The % operator gives remainder, so when rear = 4, (4+1)%5 = 0 (goes back to start)
void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }

    if (front == -1)        // very first element
        front = rear = 0;   // start both at position 0
    else
        rear = (rear + 1) % SIZE;   // move rear forward (wraps around using %)

    queue[rear] = value;
    printf("Inserted %d\n", value);
}

// Remove element from front
// Also uses % for circular movement
int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Queue is empty.\n");
        return -1;
    }

    int removed = queue[front];   // save the value before removing

    if (front == rear)            // only one element left
        front = rear = -1;        // reset to empty
    else
        front = (front + 1) % SIZE;   // move front forward (circular)

    printf("Deleted %d\n", removed);
    return removed;
}

// Display all elements in queue
// Tricky part: elements might wrap around
// e.g., front=3, rear=1 means elements at [3][4][0][1]
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Circular Queue: ");
    int i = front;
    
    // traverse from front to rear (might wrap around)
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;       // reached last element
        i = (i + 1) % SIZE;         // move to next (wraps around)
    }
    printf("\n");
}

int main() {
    int choice, value;

    do {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        // Input validation - scanf returns 1 if it successfully reads an int
        if (scanf("%d", &choice) != 1) {
            // Clear the junk from input buffer
            while (getchar() != '\n');  // read until newline
            printf("Invalid input! Please enter a number.\n");
            continue;  // go back to menu
        }

        switch(choice) {
            case 1:  // Enqueue
                printf("Enter value to insert: ");
                if (scanf("%d", &value) != 1) {
                    while (getchar() != '\n');
                    printf("Invalid input! Please enter a number.\n");
                    break;
                }
                enqueue(value);
                break;

            case 2:  // Dequeue
                dequeue();
                break;

            case 3:  // Display
                display();
                break;

            case 4:  // Exit
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Choice! Please enter 1-4.\n");
        }
    } while (choice != 4);

    return 0;
}