#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

Node *createNode(int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node **head, int data)
{
    Node *newNode = createNode(data);
    if(*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// void insertAtFront(Node *head, int data)
// {
//     Node *newNode = createNode(data);

// }

void displayList(Node *head)
{
    Node *temp = head;
    while(temp != NULL)
    {
        printf("%d ->", temp->data);

    }
}

void deleteNode(Node **head, int data)
{
    Node *temp = *head;
    Node *prev = NULL;

    if(temp != NULL && temp->data == data){
        *head = temp->next;
        free(temp);
        return;
    }

    while ((temp != NULL && temp->data != data))
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        return;
    }

    prev->next = temp->next;
    free(temp);
}

int main ()
{
    Node *head = NULL;
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    
    printf("List after inserting at the end: ");
    displayList(head);

    // insertAtFront(&head,10);
    // insertAtFront(&head,20);
    // insertAtFront(&head,30);
    


    return 0;
}