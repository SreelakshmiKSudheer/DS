#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list representing a term in the polynomial
typedef struct Node {
    float coeff;    // Coefficient of the term
    int exp;        // Exponent of the term
    struct Node *link;  // Pointer to the next term in the polynomial
} Node;

// Define a structure for a polynomial
typedef struct Poly {
    Node *header;   // Header node of the polynomial linked list
} Poly;

// Define global polynomial variables P, Q, and R
Poly P, Q, R;

// Function to create a new node with given coefficient and exponent
Node* getNode(float coeff, int exp) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->coeff = coeff;
        newNode->exp = exp;
        newNode->link = NULL;
    }
    return newNode;
}

// Function to read polynomial terms from user input and store them in a linked list
void readPoly(Node *header, Node *ptr, int n) {
    float coeff;
    int exp;
    for (int i = 0; i < n; i++) {
        scanf("%f %d", &coeff, &exp);
        Node* New = getNode(coeff, exp);
        ptr->link = New;
        ptr = New;
    }
}

// Function to display the polynomial stored in a linked list
void display(Node *header) {
    Node *ptr = header->link;
    if (ptr == NULL) {
        printf("No elements, cannot display\n");
        return;
    }
    while (ptr != NULL) {
        printf("%.2fx^%d ", ptr->coeff, ptr->exp);
        if (ptr->link != NULL)
            printf("+ ");
        ptr = ptr->link;
    }
    printf("\n");
}

// Function to multiply two polynomials and store the result in another polynomial
void Multiply(Node *PHead, Node *QHead, Node *RHead) {
    Node *Pptr = PHead->link;
    Node *Qptr = QHead->link;
    Node *Rptr = RHead;
    if (Pptr == NULL || Qptr == NULL) {
        printf("Empty operand polynomials, Resultant zero polynomial\n");
        Rptr = NULL;
        return;
    }
    while (Pptr != NULL) {
        Qptr = QHead->link;
        while (Qptr != NULL) {
            Node *New = (Node *)malloc(sizeof(Node));
            Rptr->link = New;
            Rptr = New;
            Rptr->coeff = Pptr->coeff * Qptr->coeff;
            Rptr->exp = Pptr->exp + Qptr->exp;
            Rptr->link = NULL;
            Qptr = Qptr->link;
        }
        Pptr = Pptr->link;
    }
}

int main() {
    int m, n;
    // Initialize the header nodes for polynomials P, Q, and R
    P.header = getNode(-9999, -9999);
    Q.header = getNode(-9999, -9999);
    R.header = getNode(-9999, -9999);
    Node* Pptr = P.header;
    Node* Qptr = Q.header;
    Node* Rptr = R.header;

    // Prompt the user to enter the two polynomials
    printf("Enter two polynomials in the format: Coefficient <space> Exponent\n");

    // Input for the first polynomial (P)
    printf("First polynomial:\n");
    printf("Enter the number of terms: ");
    scanf("%d", &m);
    printf("Enter the first polynomial terms:\n");
    readPoly(P.header, Pptr, m);

    // Input for the second polynomial (Q)
    printf("Second polynomial:\n");
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Enter the second polynomial terms:\n");
    readPoly(Q.header, Qptr, n);

    // Display the input polynomials
    printf("Displaying first polynomial: ");
    display(P.header);
    printf("Displaying second polynomial: ");
    display(Q.header);

    // Multiply the two input polynomials and store the result in R
    Multiply(P.header, Q.header, R.header);

    // Display the result polynomial
    printf("Displaying resultant polynomial: ");
    display(R.header);

    return 0;
}
