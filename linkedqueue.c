#include <stdio.h>
#include <stdlib.h>

// Define the structure for a single node
struct Node {
    int data;
    struct Node* next;
};

// Global pointers for the front and rear of the queue
struct Node *front = NULL;
struct Node *rear = NULL;

// Function to check if the queue is empty
int isEmpty() {
    return (front == NULL);
}

// Function to add an element to the rear of the queue (Enqueue)
void enqueue(int value) {
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Queue Overflow (Memory allocation failed)\\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    // If the queue is empty, the new node is both front and rear
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        // Otherwise, add the new node to the end and update the rear pointer
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued %d\\n", value);
}

// Function to remove an element from the front of the queue (Dequeue)
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow (Queue is empty)\\n");
        return;
    }

    // Store the front node temporarily and move the front pointer
    struct Node* temp = front;
    front = front->next;

    // If the queue becomes empty after dequeue, update the rear pointer as well
    if (front == NULL) {
        rear = NULL;
    }

    printf("Dequeued %d\\n", temp->data);
    free(temp); // Free the memory of the removed node
}

// Function to get the front element of the queue without removing it (Peek)
int peek() {
    if (isEmpty()) {
        printf("Queue is empty. No front element.\\n");
        return -1; // Return a sentinel value for error
    }
    return front->data;
}

// Function to display the elements in the queue
void display() {
    struct Node* temp = front;
    if (isEmpty()) {
        printf("Queue is empty.\\n");
        return;
    }
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\\n");
}

// Main function to demonstrate queue operations
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    printf("Front element is: %d\\n", peek());

    dequeue();
    display();

    dequeue();
    dequeue();
    dequeue(); // Attempting to dequeue from an empty queue

    return 0;
}
