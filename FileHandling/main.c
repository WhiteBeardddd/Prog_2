#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the linked list
typedef struct Node {
    char data[100];
    struct Node *next;
} Node;

// Function prototypes
Node* createNode(const char *data);
void appendNode(Node **head, const char *data);
void displayList(Node *head);
void writeToFile(const char *filename, Node *head);
Node* readFromFile(const char *filename);
void updateList(Node *head, const char *oldData, const char *newData);

int main() {
    Node *head = NULL;

    // Read data from file into linked list
    head = readFromFile("linkedlist.txt");
    printf("Initial list (read from file):\n");
    displayList(head);

    // Append a new node
    appendNode(&head, "56");
    printf("\nList after adding a new node:\n");
    displayList(head);

    // Update a node
    updateList(head, "Node 2", "Updated Node 2");
    printf("\nList after updating 'Node 2':\n");
    displayList(head);

    // Write updated list back to the file
    writeToFile("linkedlist.txt", head);

    // Free allocated memory
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

// Create a new node
Node* createNode(const char *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation error.\n");
        exit(1);
    }
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

// Append a node to the linked list
void appendNode(Node **head, const char *data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Display the linked list
void displayList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Write linked list data to a file
void writeToFile(const char *filename, Node *head) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }
    Node *temp = head;
    while (temp != NULL) {
        fprintf(file, "%s\n", temp->data);
        temp = temp->next;
    }
    fclose(file);
}

// Read linked list data from a file
Node* readFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file for reading. Starting with an empty list.\n");
        return NULL;
    }
    Node *head = NULL;
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file)) {
        // Remove newline character
        buffer[strcspn(buffer, "\n")] = '\0';
        appendNode(&head, buffer);
    }
    fclose(file);
    return head;
}

// Update a node's data in the linked list
void updateList(Node *head, const char *oldData, const char *newData) {
    Node *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->data, oldData) == 0) {
            strcpy(temp->data, newData);
            return;
        }
        temp = temp->next;
    }
    printf("Node with data '%s' not found.\n", oldData);
}
