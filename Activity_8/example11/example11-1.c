#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a node in the linked list
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Initialize the head of the linked list to NULL
Node *head = NULL;

// Function to insert a new node at the beginning of the linked list
void insert(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node)); // Allocate memory for the new node
    newNode->data = data;                         // Set the data for the new node
    newNode->next = head;                         // Point the new node to the current head
    head = newNode;                               // Update the head to the new node
}

// Function to delete a node with a specific value from the linked list
void delete(int data)
{
    Node *temp = head; // Temporary pointer to traverse the list
    Node *prev = NULL; // Pointer to keep track of the previous node

    // If the head node itself holds the data to be deleted
    if (temp != NULL && temp->data == data)
    {
        head = temp->next; // Update the head to the next node
        free(temp);        // Free the memory of the deleted node
        return;
    }

    // Search for the node to be deleted, keep track of the previous node
    while (temp != NULL && temp->data != data)
    {
        prev = temp;
        temp = temp->next;
    }

    // If the data was not found in the list
    if (temp == NULL)
        return;

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp); // Free the memory of the deleted node
}

// Function to display the linked list
void display()
{
    Node *temp = head; // Temporary pointer to traverse the list
    while (temp != NULL)
    {
        printf("%d -> ", temp->data); // Print the data of each node
        temp = temp->next;            // Move to the next node
    }
    printf("NULL\n"); // Indicate the end of the list
}

// Function to save the linked list to a file
void saveToFile(char *filename)
{
    FILE *file = fopen(filename, "w"); // Open the file in write mode
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    Node *temp = head; // Temporary pointer to traverse the list
    while (temp != NULL)
    {
        fprintf(file, "%d\n", temp->data); // Write the data of each node to the file
        temp = temp->next;                 // Move to the next node
    }

    fclose(file); // Close the file
}

// Function to load the linked list from a file
void loadFromFile(const char *filename)
{
    FILE *file = fopen(filename, "r"); // Open the file in read mode
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    int data;
    while (fscanf(file, "%d", &data) != EOF) // Read the data from the file
    {
        insert(data); // Insert the data into the linked list
    }

    fclose(file); // Close the file
}

int main()
{
    // Fixed filename for saving and loading the linked list
    char *filename = "linkedlist.txt";

    // Insert nodes with values 10, 20, and 30 into the linked list
    // insert(10);
    // insert(20);
    // insert(30);
    // insert(40);
    // insert(50);
    // insert(60);

    // // // Display the current state of the linked list
    // display();

    // // // Delete the node with value 20 from the linked list
    // delete (20);

    // // // Display the linked list after deletion
    // display();

    // // // Save the current state of the linked list to a file
    // saveToFile(filename);

    // // Clear the linked list by setting the head to NULL
    // head = NULL;

    // Load the linked list from the file
    loadFromFile(filename);

    // Display the linked list after loading from the file
    display();

    return 0;
}
