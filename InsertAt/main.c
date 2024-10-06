// InsertAtLinklist

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void createNode(struct Node **, int data)
{
    struct Node* new_node = (struct Node *)malloc(sizeof(struct Node));
    
    new_node->data = data;
    new_node->next = NULL;
    
    return new_node;
}

void insertAt(struct Node **head, int data, int pos)
{
    struct Node* new_node = createNode(data);
    
    if(pos == 0){
        new_node->next = *head;
        *head = new_node;
    }
    
    for(int i = 0;)
    
    return new_node;
}


int main ()
{
    struct Node *head = NULL;
    
    insertAt(&head, 10, 1);
    insertAt(&head, 20, 1);
    insertAt(&head, 30, 2);
    insertAt(&head, 40, 3)
}
