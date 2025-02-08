#include <stdio.h>
#include <stdlib.h>

#define INVALID -99999

typedef struct Node
{
    int data;
    struct Node *link;
}Node;

Node* a[20];
int top;

void push(Node *item)
{
    a[++top] = item;
}

Node* pop()
{
    while(top > -1)
        return a[top--];
}
Node* getNode(int item)
{
    Node *New = (Node *)malloc(sizeof(Node));

    New->data = item;
    New->link = NULL;

    return New;
}

Node* createNode(int n)
{
    int item;

    Node *header = (Node *)malloc(sizeof(Node));

    header->data = -9999;
    header->link = header;

    Node *ptr = header->link;

    printf("Enter items: \n");

    for(int i = 0; i < n;i++)
    {
           scanf("%d",&item);

           Node *New = getNode(item);
           New->link = header;
           ptr->link = New;
           ptr = ptr->link;

    }

    return header;
    

}

void display(Node *header)
{
    Node *ptr = header->link;

    printf("Displaying elements of the list:\n");

    while(ptr != header)
    {
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

void Free(Node *header)
{
    Node *ptr = header->link;
    Node *ptr1 = header;
    while(ptr != header)
    {
        ptr1 = ptr->link;
        free(ptr);
        ptr = ptr1;
    }

    free(header);
}

void reverse(Node *header)
{


    //int i = 0,last;

    Node *ptr = header->link;

    while(ptr != header)
    {
        push(ptr);
        ptr = ptr->link;
    }    

    ptr = header;

    while(top > -1)
    {
        Node *ptr1 = pop();
        ptr1->link = header;
        ptr->link = ptr1;
        ptr = ptr1;


    }
}

int main()
{
    int n;
    top = -1;
    

    printf("Enter the no. of elements in the list: ");
    scanf("%d",&n);

    Node *header = createNode(n);
    display(header);
    reverse(header);
    display(header);
    Free(header);
}