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
    struct Node *next;
}Node, *NodePtr;

Node createIntNode(int value)
{
    Node *newIntNode = malloc(sizeof(Node));
    newIntNode->datatype = INT_TYPE;
    newIntNode->data.i = value;
}

void displayList()
{

}

int main()
{

    return 0;
}

