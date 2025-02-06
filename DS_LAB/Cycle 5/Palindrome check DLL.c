#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    char data;
    struct Node *llink;
    struct Node *rlink;
}Node;

Node *header;

Node* getNode(char value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode != NULL)
    {
        newNode->data = value;
        newNode->llink = NULL;
        newNode->rlink = NULL;
    }

    return newNode;
}

void Free(Node *header)
{
    Node *ptr = header->rlink;
    Node *ptr1 = header;

    while(ptr != NULL)
    {
        ptr1 = ptr->rlink;
        free(ptr);
        ptr = ptr1;
    }
    free(header);
}

int main()
{
    int len,palin = 1;
    char str[20],item;
    header = getNode('\0');

    printf("Enter a string: ");
    scanf("%s",str);
    
    Node* tmp=header;
    for(len = 0; str[len] != '\0'; len++)
    {
        Node *New = getNode(str[len]);
        New->llink = tmp;
        tmp->rlink = New;
        tmp=tmp->rlink;
    }
    int half = len/2;

    Node* l=header->rlink;
    Node* r=tmp;
    for(int i = 0; i < half; i++)
    {
        if((l->data) != (r->data))
        {
            printf("Not a palindrome\n");
            palin = 0;
            break;
        }
        l=l->rlink;
        r=r->llink;
    }

    if(palin)
        printf("Palindrome\n");

    Free(header);
}

