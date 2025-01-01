#include <stdio.h>
#include <stdlib.h>
#define MAX 10

enum Datatype
{
    INT_TYPE,
    FLOAT_TYPE
};

union Data
{
    int i;
    float f;
};

typedef struct node
{
    enum Datatype datatype;
    union Data data;
    struct node *next;
}Node;

Node *createIntNode(int value)
{
    Node *newIntNode = malloc(sizeof(Node));
    newIntNode->datatype = INT_TYPE;
    newIntNode->data.i = value;
    newIntNode->next = NULL;

    return newIntNode;
}

Node *createFloatNode(float value)
{
    Node *newFloatNode = malloc(sizeof(Node));
    newFloatNode->datatype = FLOAT_TYPE;
    newFloatNode->data.f = value;
    newFloatNode->next = NULL;

    return newFloatNode;
}

void connectHead(Node **head, Node* newNode)
{
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

void displayList(Node* head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        if(temp->datatype == INT_TYPE)
        {
            printf("%d\n", temp->data.i);
        }
        else if(temp->datatype == FLOAT_TYPE)
        {
            printf("%.2f\n", temp->data.f);
        }
        temp = temp->next;
    }
}

int main()
{
    Node *head = NULL;

    connectHead(&head, createFloatNode(7.9));
    connectHead(&head, createIntNode(1));
    connectHead(&head, createFloatNode(5.3));
    connectHead(&head, createIntNode(4));

    displayList(head);

    Node *current = head;

    while (current->next != NULL)
    {
        Node *trav = current->next;
        free(current);
        current = trav  ; 
    }
    


    return 0;
}

