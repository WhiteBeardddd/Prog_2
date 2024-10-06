#include <stdio.h>
#include <stdlib.h>

// Typedef for the Node structure
typedef struct node {
    int data;
    struct node *next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at a specific position
void insertAt(Node **head, int data, int pos) {
    Node* new_node = createNode(data);

    if (pos == 0) { // Inserting at the head
        new_node->next = *head;
        *head = new_node;
        return;
    }

    Node* temp = *head;
    for (int i = 0; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position is out of bounds\n");
        free(new_node);
    } else {
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;

    insertAt(&head, 10, 0); // Insert at position 0
    insertAt(&head, 20, 1); // Insert at position 1
    insertAt(&head, 30, 2); // Insert at position 2
    insertAt(&head, 40, 3); // Insert at position 3

    printList(head); // Print the list

    return 0;
}
