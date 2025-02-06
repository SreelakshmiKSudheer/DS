#include <stdio.h>
#include <stdlib.h>

#define INVALID -99999

typedef struct Node
{
    int data;
    struct Node *link;
}Node;

Node* getNode(int item)
{
    Node *newNode = (Node*)malloc(sizeof(Node));

    if(newNode != NULL)
    {
        newNode->data = item;
        newNode->link = NULL;
    }

    return newNode;
}


void insertFront(Node *header,int item)
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

void insertEnd(Node *header,int item)
{
    Node *New = getNode(item);
    Node *ptr;

    if(New != NULL)
    {
        ptr = header;

        while(ptr->link != NULL)
        {
            ptr = ptr->link;
        }

        ptr->link = New;
    }
    else
        printf("Unable to allocate memory\n");
}

void insertArbitary(Node *header,int item,int pos)
{
    Node *New = getNode(item);
    Node *ptr;

    if(New != NULL)
    {
        ptr = header;

        while(ptr != NULL && ptr->data != pos)
        {
            ptr = ptr->link;
        }

        if(ptr->data == pos)
        {
            New->link = ptr->link;
            ptr->link = New;
        }
        else
            printf("No element with datapart %d\n",pos);
    }
    else
        printf("Unable to allocate memory\n");
}


int deleteFront(Node *header)
{
    int item;
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
        printf("List empty. Unable to delete from list. \n");
        return INVALID;
    }
}


int deleteEnd(Node *header)
{
    int item;

    if(header->link != NULL)
    {
        Node *ptr = header;
        Node *ptr1 = ptr;

        while(ptr->link != NULL)
        {
            ptr1 = ptr;
            ptr = ptr->link;
        }
        
        item = ptr->data;
        ptr1->link = NULL;
        free(ptr);
        return item;
    }
    else
    {
        printf("List empty. Unable to delete from list. \n");
        return INVALID;
    }
}

int deleteArbitary(Node *header,int pos)
{
    int item;

    if(header->link != NULL)
    {
        Node *ptr = header;
        Node *ptr1 = ptr;

        while(ptr->link != NULL && ptr->data != pos)
        {
            ptr1 = ptr;
            ptr = ptr->link;
        }
        
        if(ptr->data == pos)
        {
            item = ptr->data;
            ptr1->link = ptr->link;
            free(ptr);
            return item;
        }
        else
        {
            return INVALID;
        }
    }
    else
    {
        printf("List empty. Unable to delete from list. \n");
        return INVALID;
    }
}

void display(Node *header)
{
    Node *ptr = header->link;

    if(ptr == NULL)
    {
        printf("No element, cannot display\n");
        return ;

    }

    printf("Displaying elements of the list\n");

    while(ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}


void Free(Node *header)
{
        Node *ptr = header;
        Node *ptr1 = ptr;

        while(ptr != NULL)
        {
            ptr1 = ptr->link;
            free(ptr);
            ptr = ptr1;
        }
    
}

int main()
{
    int choice,item,pos;
    Node *header = getNode(-99999);

    printf("Enter \n1] Insert Front");
    printf("\n2] Insert End");
    printf("\n3] Insert at Arbitary position");

    printf("\n4] Delete Front");
    printf("\n5] Delete End");
    printf("\n6] Delete at Arbitary position");

    printf("\n7] Display");
    printf("\n8] Quit");
    
    
    
    do
    {
        printf("\nEnter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1 : printf("Enter item: ");
                    scanf("%d",&item);
                    insertFront(header,item);
                    break;
            case 2: printf("Enter item: ");
                    scanf("%d",&item);
                    insertEnd(header,item);
                    break;
            case 3: printf("Enter item and position: ");
                    scanf("%d %d",&item,&pos);
                    insertArbitary(header,item,pos);
                    break;

            case 4: item = deleteFront(header);
                    if(item == INVALID)
                        printf("List empty. Cannot delete element\n");
                    else
                        printf("Deleted item = %d\n",item);
                    break;

            case 5: item = deleteEnd(header);
                    if(item == INVALID)
                        printf("List empty. Cannot delete element\n");
                    else
                        printf("Deleted item = %d\n",item);
                    break;

            case 6: printf("Enter where to be deleted: ");
                    scanf("%d",&pos);
            
                    item = deleteArbitary(header,pos);
                    if(item == INVALID)
                        printf("List empty. Cannot delete element\n");
                    else
                        printf("Deleted item = %d\n",item);
                    break;


            case 7: display(header);
                    break;
            case 8: break;

            default: printf("Entered choice is INVALID\n");
        }

    }while(choice != 8);

    Free(header);
}
