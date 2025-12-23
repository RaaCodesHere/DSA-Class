#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Front and Rear pointers
struct Node* front = NULL;
struct Node* rear = NULL;

// Check if queue is empty
int isEmpty() {
    return front == NULL;
}

// Enqueue operation
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Queue Overflow (Memory allocation failed)\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Enqueued %d\n", value);
}

// Dequeue operation
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow (Queue is empty)\n");
        return;
    }

    struct Node* temp = front;
    printf("Dequeued %d\n", temp->data);

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

// Peek operation
int peek() {
    if (isEmpty()) {
        printf("Queue is empty. No front element.\n");
        return -1;
    }
    return front->data;
}

// Display queue elements
void display() {
    struct Node* temp = front;

    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    printf("Front element is: %d\n", peek());

    dequeue();
    display();

    dequeue();
    dequeue();
    dequeue(); // Underflow case

    return 0;
}
