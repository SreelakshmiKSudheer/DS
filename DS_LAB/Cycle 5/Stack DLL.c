#include <stdio.h>
#include <stdlib.h>

#define INVALID -99999

// Node structure representing a doubly linked list node
typedef struct Node
{
    int data;             // Data stored in the node
    struct Node *llink;   // Pointer to the previous node (left link)
    struct Node *rlink;   // Pointer to the next node (right link)
} Node;

Node *header, *tail;      // Global pointers to the header and tail nodes

// Function to push a new node onto the top of the stack
// Parameters:
// - header: Pointer to the header node
// - top: Pointer to the top of the stack (pointer to pointer)
// - data: Data to be pushed onto the stack
void push(Node *header, Node **top, int data)
{
    Node *New = (Node *)malloc(sizeof(Node));

    if (New == NULL)
        printf("Memory Underflow\n");
    else
    {
        New->data = data;
        New->rlink = *top;
        New->llink = header;

        // Update the links to insert the new node
        (*top)->llink = New;
        *top = New;
        header->rlink = *top;
    }
}

// Function to pop a node from the top of the stack
// Parameters:
// - header: Pointer to the header node
// - top: Pointer to the top of the stack (pointer to pointer)
// Returns:
// - The data of the popped node, or INVALID if the stack is empty
int pop(Node *header, Node **top)
{
    int item;

    if (*top == tail)
        return INVALID;
    else
    {
        // Get the data of the top node
        item = (*top)->data;

        // Update the links to remove the top node
        Node *ptr = (*top)->rlink;
        ptr->llink = header;
        header->rlink = ptr;

        // Free the memory of the top node
        free(*top);

        // Update top to point to the next node
        *top = ptr;

        // Return the popped item
        return item;
    }
}

// Function to display the elements of the stack
// Parameters:
// - top: Pointer to the top of the stack
// - tail: Pointer to the tail node
void display(Node *top, Node *tail)
{
    Node *ptr = tail->llink;

    if (top == tail)
    {
        // Stack is empty
        printf("Stack empty\n");
        return;
    }

    // Traverse and print the elements of the stack
    while (ptr != top->llink)
    {
        printf("%d ", ptr->data);
        ptr = ptr->llink;
    }
    printf("\n");
}

// Function to free the memory allocated for the nodes in the stack
// Parameters:
// - header: Pointer to the header node
// - tail: Pointer to the tail node
void Free(Node *header, Node *tail)
{
    Node *ptr = header;
    Node *ptr1 = ptr;

    // Traverse the nodes and free the memory
    while (ptr != NULL)
    {
        ptr1 = ptr->rlink;
        free(ptr);
        ptr = ptr1;
    }
}

// Main function
int main()
{
    int choice, item;

    // Allocate memory for the header and tail nodes
    header = (Node *)malloc(sizeof(Node));
    tail = (Node *)malloc(sizeof(Node));
    header->llink = NULL;
    header->rlink = tail;
    tail->llink = header;
    tail->rlink = NULL;

    Node *top = header->rlink;

    // Menu-driven loop
    printf("Enter \n1] Push");
    printf("\n2] Pop");
    printf("\n3] Display");
    printf("\n4] Quit");

    do
    {
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter item: ");
            scanf("%d", &item);
            push(header, &top, item);
            break;
        case 2:
            item = pop(header, &top);
            if (item == INVALID)
                printf("Empty\n");
            else
                printf("Deleted item: %d\n", item);
            break;
        case 3:
            display(top, tail);
            break;
        case 4:
            break;
        default:
            printf("Invalid Input\n");
        }
    } while (choice != 4);

    // Free the memory allocated for the nodes
    Free(header, tail);

    return 0;
}
