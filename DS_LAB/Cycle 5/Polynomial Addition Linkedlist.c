#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    float coeff;
    int exp;
    struct Node *link;
}Node;

typedef struct Poly
{
    Node *header;

}Poly;

Poly P,Q,R;

Node* getNode(float coeff,int exp)
{
    Node *newNode = (Node*)malloc(sizeof(Node));

    if(newNode != NULL)
    {
        newNode->coeff = coeff;
        newNode->exp = exp;
        newNode->link = NULL;
    }

    return newNode;
}

void readPoly(Node *header,Node *ptr,int n)
{
    float coeff;
    int exp;

    for(int i = 0; i < n; i++)
    {
        scanf("%f %d",&coeff,&exp);
        Node* New = getNode(coeff,exp);

        ptr->link = New;
        ptr = New;

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

    //printf("Displaying elements of the list\n");

    while(ptr != NULL)
    {
        printf("%.2fx^%d ",ptr->coeff,ptr->exp);
        if (ptr->link != NULL)
            printf("+ ");
        ptr = ptr->link;
    }
    printf("\n");
}

void Sum(Node *Pptr, Node *Qptr, Node *Rptr)
{
    while(Pptr != NULL && Qptr != NULL)
    {
        if(Pptr->exp == Qptr->exp)
        {
            Node *New = (Node *)malloc(sizeof(Node));

            Rptr->link = New;
            Rptr = New;
            Rptr->coeff = Pptr->coeff + Qptr->coeff;
            Rptr->exp = Pptr->exp;
            Rptr->link = NULL;
            Pptr = Pptr->link;
            Qptr = Qptr->link;
        }
        else if(Pptr->exp > Qptr->exp)
        {
            Node *New = (Node *)malloc(sizeof(Node));

            Rptr->link = New;
            Rptr = New;
            Rptr->coeff = Pptr->coeff;
            Rptr->exp = Pptr->exp;
            Rptr->link = NULL;
            Pptr = Pptr->link;
        }
        else
        {
            Node *New = (Node *)malloc(sizeof(Node));

            Rptr->link = New;
            Rptr = New;
            Rptr->coeff = Qptr->coeff;
            Rptr->exp = Qptr->exp;
            Rptr->link = NULL;
            Qptr = Qptr->link;
        }

    }

    while (Pptr != NULL)
    {
        Node *New = (Node *)malloc(sizeof(Node));

        Rptr->link = New;
        Rptr = New;
        Rptr->coeff = Pptr->coeff;
        Rptr->exp = Pptr->exp;
        Rptr->link = NULL;
        Pptr = Pptr->link;
    }

    while(Qptr != NULL)
    {
        Node *New = (Node *)malloc(sizeof(Node));

        Rptr->link = New;
        Rptr = New;
        Rptr->coeff = Qptr->coeff;
        Rptr->exp = Qptr->exp;
        Rptr->link = NULL;
        Qptr = Qptr->link;
    }
    
}

int main()
{
    int m,n,i;
    float coeff;
    int exp;

    P.header = getNode(-9999,-9999);
    Q.header = getNode(-9999,-9999);
    R.header = getNode(-9999,-9999);

    Node* Pptr = P.header;
    Node* Qptr = Q.header;
    Node* Rptr = R.header;

    // prompt
    printf("Enter two polynomials in the below given format\n");
    printf("Coefficient <space> power\n");

    // About -  First poly
    printf("First polnomial: \n");
    printf("How many terms: ");
    scanf("%d",&m);
    printf("Enter first polnomial: \n");
    readPoly(P.header,Pptr,m);

    // About -  Second poly
    printf("Second polnomial: \n");
    printf("How many terms: ");
    scanf("%d",&n);
    printf("Enter Second polnomial: \n");
    readPoly(Q.header,Qptr,n);

    printf("Displaying first polynomial: ");
    display(P.header);

    printf("Displaying second polynomial: ");
    display(Q.header);

    Pptr = P.header->link;
    Qptr = Q.header->link;
    Rptr = R.header;

    Sum(Pptr,Qptr,Rptr);

    display(R.header);

    

}