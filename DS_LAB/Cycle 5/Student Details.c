#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INVALID -99999

// defining the node
typedef struct Node
{
    int number;
    char name[15];
    float totalMark;
    struct Node *link;
} Node;

// creation and initialization of node
Node *getNode(int number, char name[], float totalMark)
{
    Node *newNode = (Node *)malloc(sizeof(Node)); // dynamic memory allocation

    if (newNode != NULL) // memory allocation check
    {
        newNode->number = number;
        strcpy(newNode->name, name);
        newNode->totalMark = totalMark;
        newNode->link = NULL;
    }

    return newNode;
}

// inserting a node at the beginning
void insertFront(Node *header, int number, char name[], float totalMark)
{
    Node *New = getNode(number, name, totalMark);

    if (New != NULL)
    {
        New->link = header->link;
        header->link = New;
    }
    else
        printf("Unable to allocate memory\n");
}

int deleteArbitrary(Node *header, int number)
{
    int item;

    if (header->link != NULL)
    {
        Node *ptr = header;
        Node *ptr1 = ptr;

        while (ptr->link != NULL && ptr->number != number)
        {
            ptr1 = ptr;
            ptr = ptr->link;
        }

        if (ptr->number == number)
        {
            item = ptr->number;
            printf("Number: %d\n", ptr->number);
            printf("Name: %s\n", ptr->name);
            printf("Total Mark: %f\n", ptr->totalMark);

            ptr1->link = ptr->link;
            free(ptr);
            return item;
        }
    }
    else
    {
        return INVALID;
    }
    return INVALID; // added to handle the case when the number is not found
}

void display(Node *header)
{
    Node *ptr = header->link;

    if (ptr == NULL)
    {
        printf("No element, cannot display\n");
        return;
    }

    printf("Displaying elements of the list\n");
    printf("No.     Name        Total Mark\n"); // added newline character

    while (ptr != NULL)
    {
        printf("%2d %5s %8f\n", ptr->number, ptr->name, ptr->totalMark);
        ptr = ptr->link;
    }
    printf("\n");
}

void Free(Node *header)
{
    Node *ptr = header;
    Node *ptr1 = ptr;

    while (ptr != NULL)
    {
        ptr1 = ptr->link;
        free(ptr);
        ptr = ptr1;
    }
}

Node *searchNum(Node *header, int number)
{
    if (header->link != NULL)
    {
        Node *ptr = header;
        Node *ptr1 = ptr;

        while (ptr->link != NULL && ptr->number != number)
        {
            ptr1 = ptr;
            ptr = ptr->link;
        }

        if (ptr->number == number)
        {
            printf("Student found\n");
            printf("Number: %d\n", ptr->number);     // added newline character
            printf("Name: %s\n", ptr->name);         // added newline character
            printf("Total Mark: %f\n", ptr->totalMark); // added newline character

            return ptr;
        }
    }
    else
    {
        printf("Student not found\n");
    }
    return NULL; // added to handle the case when the number is not found
}

Node *searchName(Node *header, char name[])
{
    if (header->link != NULL)
    {
        Node *ptr = header->link; // Start from the first node
        int same = 0; // Initialize same variable to 0

        while (ptr != NULL) // Continue until ptr becomes NULL
        {
            if (strcasecmp(ptr->name, name) == 0)
            {
                same = 1;
                break;
            }
            ptr = ptr->link; // Move to the next node
        }

        if (same)
        {
            printf("Student found\n");
            printf("Number: %d\n", ptr->number);     // added newline character
            printf("Name: %s\n", ptr->name);         // added newline character
            printf("Total Mark: %f\n", ptr->totalMark); // added newline character

            return ptr;
        }
    }
    else
    {
        printf("Student not found\n");
    }
    return NULL; // added to handle the case when the name is not found
}

void sort(Node *header)
{
    int swapped = 0;
    Node *ptr, *lastptr = NULL;

    if (header->link == NULL)
        return;

    do
    {
        swapped = 0;
        ptr = header->link;

        while (ptr->link != lastptr)
        {
            if (ptr->number > ptr->link->number)
            {
                Node *temp = ptr;

                ptr->number = ptr->link->number;
                ptr->totalMark = ptr->link->totalMark;
                strcpy(ptr->name, ptr->link->name);

                ptr->link->number = temp->number;
                ptr->link->totalMark = temp->totalMark;
                strcpy(ptr->link->name, temp->name);
                swapped = 1;
            }

            ptr = ptr->link;
        }
        lastptr = ptr;
    } while (swapped);
}

int main()
{
    int choice, number, item;
    char name[15];
    float totalMark;

    Node *header = getNode(-99999, "", -99999);

    printf("Enter \n1] Insert Front");
    printf("\n2] Delete by entering the number ");
    printf("\n3] Display");

    printf("\n4] Search by Number");
    printf("\n5] Search by Name");
    printf("\n6] Sort");

    printf("\n7] Quit");

    do
    {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter number: ");
            scanf("%d", &number);
            printf("Enter name: ");
            scanf(" %[^\n]", name);
            printf("Enter total mark: ");
            scanf("%f", &totalMark);
            insertFront(header, number, name, totalMark);
            break;

        case 2:
            printf("Enter number of student to be deleted: ");
            scanf("%d", &number);

            item = deleteArbitrary(header, number);
            if (item == INVALID)
                printf("List empty. Cannot delete element\n");
            else
                printf("Deleted\n");
            break;

        case 3:
            display(header);
            break;

        case 4:
            printf("Enter number: ");
            scanf("%d", &number);
            searchNum(header, number);
            break; // added break statements for each case

        case 5:
            printf("Enter name: ");
            scanf(" %[^\n]", name);
            searchName(header, name);
            break; // added break statements for each case

        case 6:
            printf("List before sorting: \n");
            display(header);
            printf("List after sorting: \n");
            sort(header);
            display(header); // added display after sorting
            break;           // added break statements for each case

        case 7:
            break; // added break statements for each case

        default:
            printf("Entered choice is INVALID\n");
        }

    } while (choice != 7);

    Free(header);
    return 0;
}
