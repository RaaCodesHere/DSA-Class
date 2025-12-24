#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Insert at beginning
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = *head_ref;

    if (*head_ref != NULL) {
        (*head_ref)->prev = new_node;
    }

    *head_ref = new_node;
}

// Insert at end
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    // If list is empty
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    // Move to last node
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
    new_node->prev = last;
}

// Insert after a given node
void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;

    if (new_node->next != NULL) {
        new_node->next->prev = new_node;
    }
}

// Delete a node
void deleteNode(struct Node** head_ref, struct Node* del) {
    if (*head_ref == NULL || del == NULL) {
        return;
    }

    if (*head_ref == del) {
        *head_ref = del->next;
    }

    if (del->next != NULL) {
        del->next->prev = del->prev;
    }

    if (del->prev != NULL) {
        del->prev->next = del->next;
    }

    free(del);
}

// Print the list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Add elements
    push(&head, 10);
    push(&head, 8);
    append(&head, 4);
    append(&head, 2);

    printf("Original List: ");
    printList(head);

    // Insert after second node
    insertAfter(head->next, 6);
    printf("After inserting 6 after second node: ");
    printList(head);

    // Delete a node
    deleteNode(&head, head->next);
    printf("After deleting second node: ");
    printList(head);

    return 0;
}
