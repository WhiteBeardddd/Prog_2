#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// Enum to specify data type in a node
enum DataType
{
    INT,
    FLOAT,
};

enum Status
{
    PENDING,
    COMPLETED,
    FAILED
};

// Union to store either an integer or a float in the same memory space
union Data
{
    int i;
    float f;
};

// Structure for a linked list node
struct Node
{
    enum DataType type; // Type of data stored in the union
    union Data data;    // Data storage (either int or float)
    struct Node *next;  // Pointer to the next node
};

// Function to create a new node with integer data
struct Node *createIntNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->type = INT;
    newNode->data.i = value;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new node with float data
struct Node *createFloatNode(float value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->type = FLOAT;
    newNode->data.f = value;
    newNode->next = NULL;
    return newNode;
}

// Function to display the list
void displayList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        if (current->type == INT)
        {
            printf("Integer: %d\n", current->data.i);
        }
        else if (current->type == FLOAT)
        {
            printf("Float: %.2f\n", current->data.f);
        }
        current = current->next;
    }
}

int main()
{
    // Creating nodes with different types of data
    struct Node *head = createIntNode(10);
    head->next = createFloatNode(3.14);
    head->next->next = createIntNode(20);

    // Display the list
    displayList(head);

    // Free memory
    struct Node *current = head;
    while (current != NULL)
    {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
