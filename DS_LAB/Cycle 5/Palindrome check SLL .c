#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    char data;
    struct Node *link;
}Node;

Node *header;

Node* getNode(char item)
{
    Node *newNode = (Node*)malloc(sizeof(Node));

    if(newNode != NULL)
    {
        newNode->data = item;
        newNode->link = NULL;
    }

    return newNode;
}


void insertFront(Node *header,char item)
{
    Node *New = getNode(item);

    if(New != NULL)
    {
        New->link = header->link;
        header->link = New;
    }
    else
        printf("Unable to allocate memory\n");
}

char deleteFront(Node *header)
{
    char item;
    if(header->link != NULL)
    {
        Node *ptr = header->link;
        item = ptr->data;
        header->link = ptr->link;
        free(ptr);
        return item;
    }
    else
    {
        return '\0';
    }
}

int main()
{
    int len,palin = 1;
    char str[20],item;
    header = getNode('\0');

    printf("Enter a string: ");
    scanf(" %[^\n]",str);

    for(len = 0; str[len] != '\0'; len++)
    {
        insertFront(header,str[len]);
    }

    int half = len/2;

    for(int i = 0; i < half; i++)
    {
        item = deleteFront(header);

        if(item != str[i])
        {
            printf("Not a palindrome\n");
            palin = 0;
            break;
        }
        
    }

    if(palin)
        printf("Palindrome\n");
}