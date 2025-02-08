#include <stdio.h>
#include <stdlib.h>

#define INVALID -99999

typedef struct Node
{
    int data;
    struct Node *llink;
    struct Node *rlink;
}Node;

Node *header;

Node* getNode(int value)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode != NULL)
    {
        newNode->data = value;
        newNode->llink = NULL;
        newNode->rlink = NULL;
    }

    return newNode;
}

void insertFront(Node* header, int item)
{
    Node *New = getNode(item);

    // check for availability of memory
    if (New != NULL)
    {
        Node *ptr = header->rlink;

        New->llink = header;
        header->rlink = New;
        New->rlink = ptr;

        // Update the ll of the next node
        if (ptr != NULL)
            ptr->llink = New;
    }
    else
        printf("Unable to allocate memory\n");
}



void insertEnd(Node* header, int item)
{
    Node *ptr = header;

    while (ptr->rlink != NULL)
    {
        ptr = ptr->rlink;
    }

    Node *New = getNode(item);

    // check for availability of memory
    if (New != NULL)
    {
        New->llink = ptr;
        New->rlink = NULL;
        ptr->rlink = New;

        // Update the ll of the previous last node
        if (ptr != header)
            (New->llink)->rlink = New;
    }
    else
        printf("Unable to allocate memory\n");
}

void insertArbitary(Node* header,int item,int pos)
{
    Node *New = getNode(item);

    // check for availibility of memory
    if(New != NULL)
    {
        Node *ptr = header;

        while(ptr != NULL && ptr->data != pos)
        {
            ptr = ptr->rlink;
        }

        if(ptr->data == pos)
        {
            if(ptr->rlink == NULL)
            {
                New->rlink = NULL;
                New->llink = ptr;
                ptr->rlink = New;
            }
            else
            {
                Node *ptr1 = ptr->rlink;
                New->rlink = ptr1;
                ptr1->llink = New;
                ptr->rlink = New;
                New->llink = ptr;
            }
            
            
        }
        else
            printf("No element with datapart %d\n",pos);
    }
    else
    {
        printf("Unable to allocate memory\n");
        return;
    }
}

int deleteFront(Node *header)
{
    int item;

    // check whether list is empty or not
    if(header->rlink == NULL)
    {
        return INVALID;
    }
    else
    {
        Node *ptr = header->rlink;
        item = ptr->data;

        header->rlink = ptr->rlink;
        if(ptr->rlink != NULL)
            (ptr->rlink)->llink = header;

        free(ptr);
        return item;
    }

}

int deleteEnd(Node *header)
{
    int item;

    // check whether list is empty or not
    if(header->rlink == NULL)
    {
        return INVALID;
    }
    else
    {
        Node *ptr = header;
        Node *ptr1 = ptr;

        while(ptr->rlink != NULL)
        {
            ptr1 = ptr;
            ptr = ptr->rlink;
        }
        
        item = ptr->data;
        ptr1->rlink = NULL;
        free(ptr);
        return item;
    }

}

int deleteArbitary(Node *header,int pos)
{
    int item;

    // check whether list is empty or not
    if(header->rlink == NULL)
    {
        return INVALID;
    }
    else
    {
        Node *ptr = header;
        Node *ptr1 = ptr;

        while(ptr != NULL && ptr->data != pos)
        {
            ptr1 = ptr;
            ptr = ptr->rlink;
        }
        
        if(ptr->data == pos)
        {
            item = ptr->data;
            ptr1->rlink = ptr->rlink;
            
            if((ptr->rlink) != NULL)
                (ptr->rlink)->llink= ptr1;
            free(ptr);
            return item;
        }
        else
            printf("No element with datapart %d\n",pos);
    }
    return INVALID;

}

void display(Node *header)
{
    Node *ptr = header->rlink;

    if(ptr == NULL)
    {
        printf("No element, cannot display\n");
        return ;

    }

    printf("Displaying elements of the list\n");

    while(ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->rlink;
    }
    printf("\n");
}

void Free(Node *header)
{
        Node *ptr = header;
        Node *ptr1 = ptr;

        while(ptr != NULL)
        {
            ptr1 = ptr->rlink;
            free(ptr);
            ptr = ptr1;
        }
    
}

int main()
{
    int choice,item,pos;
    header = getNode(-99999);

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