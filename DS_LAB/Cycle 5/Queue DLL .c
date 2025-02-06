#include <stdio.h>
#include <stdlib.h>

#define INVALID -99999

// Node structure representing a doubly linked list node
typedef struct Node
{
    int data;            // Data stored in the node
    struct Node *llink;  // Pointer to the previous node (left link)
    struct Node *rlink;  // Pointer to the next node (right link)
} Node;

Node *header, *tail;  // Global pointers to the header and tail nodes

// Function to enqueue (insert) a new node at the rear of the queue
// Parameters:
// - header: Pointer to the header node
// - tail: Pointer to the tail node
// - front: Pointer to the front of the queue (pointer to pointer)
// - rear: Pointer to the rear of the queue (pointer to pointer)
// - data: Data to be enqueued
void enqueue(Node *header, Node *tail, Node **front, Node **rear, int data)
{
    // Create a new node
    Node *New = (Node *)malloc(sizeof(Node));

    if (New == NULL) {
        // Memory allocation failed
        printf("Memory Underflow\n");
    } else {
        // Initialize the new node
        New->data = data;
        New->rlink = tail;        // New node points to the tail
        New->llink = *rear;       // New node's left link points to the current rear

        if (*front == tail) {
            // If the queue is empty, update front to point to the new node
            *front = New;
        }
        
        // Update the links of the existing nodes
        (*rear)->rlink = New;
        *rear = New;
        tail->llink = *rear;
    }
}

// Function to dequeue (remove) a node from the front of the queue
// Parameters:
// - header: Pointer to the header node
// - tail: Pointer to the tail node
// - front: Pointer to the front of the queue (pointer to pointer)
// Returns:
// - The data of the dequeued node, or INVALID if the queue is empty
int dequeue(Node *header, Node *tail, Node **front)
{
    int item;

    if (*front == tail) {
        // Queue is empty
        return INVALID;
    } else {
        // Get the data of the front node
        item = (*front)->data;

        // Update the links to remove the front node
        Node *ptr = (*front)->rlink;
        ptr->llink = header;
        header->rlink = ptr;

        // Free the memory of the front node
        free(*front);
        
        // Update front to point to the next node
        *front = ptr;
        
        // Return the dequeued item
        return item;
    }
}

// Function to display the contents of the queue
// Parameters:
// - front: Pointer to the front of the queue
// - rear: Pointer to the rear of the queue
void display(Node *front, Node *rear)
{
    Node *ptr = front;

    if (front == tail) {
        // Queue is empty
        printf("Queue empty\n");
    } else {
        // Traverse and print the elements of the queue
        while (ptr != rear->rlink) {
            printf("%d ", ptr->data);
            ptr = ptr->rlink;
        }
        printf("\n");
    }
}

// Function to free the memory allocated for the nodes in the queue
// Parameters:
// - header: Pointer to the header node
// - tail: Pointer to the tail node
void Free(Node *header, Node *tail) {
    Node *ptr = header;
    Node *ptr1 = ptr;

    // Traverse the nodes and free the memory
    while (ptr != NULL) {
        ptr1 = ptr->rlink;
        free(ptr);
        ptr = ptr1;
    }
}

// Main function
int main()
{
    int choice, item;
    
    // Initialize the header and tail nodes
    header = (Node *)malloc(sizeof(Node));
    tail = (Node *)malloc(sizeof(Node));
    header->llink = NULL;
    header->rlink = tail;
    tail->llink = header;
    tail->rlink = NULL;

    Node *front = header->rlink;
    Node *rear = tail->llink;

    // Menu-driven loop
    printf("Enter \n1] Enqueue");
    printf("\n2] Dequeue");
    printf("\n3] Display");
    printf("\n4] Quit");

    do {
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("Enter item: ");
                scanf("%d", &item);
                enqueue(header, tail, &front, &rear, item);
                break;
            case 2: 
                item = dequeue(header, tail, &front);
                if (item == INVALID)
                    printf("Empty\n");
                else
                    printf("Deleted item: %d\n", item);
                break;
            case 3: 
                display(front, rear);
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
