#include <stdio.h>

#define SIZE 5
#define INVALID -999999

int a[SIZE],top,item;
int Q[SIZE],front,rear;

void push(int item)
{
	if(top == SIZE - 1)
		printf("Stack Overflow");
	else
		a[++top] = item;
}

int pop()
{
	if(top == -1)
		printf("Stack underflow");
	else
		item = a[top--];
}


void enqueue(int item)
{
	if(rear == SIZE - 1)
		printf("Queue overflow\n");
	else
	{
                if(front == -1)
                        front = 0;
                Q[++rear] = item;
        }

}

int dequeue()
{
	int item;
	if(front == -1){
		
		return INVALID;
	}
	else
	{
		item = Q[front++];
		if(front == rear + 1)
			front = rear = -1;
		return item;
	}
}

void display()
{
	int i;

	if(front == -1)
		printf("Queue is empty\n");
	else
	{
		for(i = front; i <= rear; i++)
			printf("%d ",Q[i]);
		printf("\n");
	}
}

void reverse()
{
    int i;

    for (i = front; i <= rear; i++)
    {
        item = dequeue();
        push(item);
    }

    while (top > -1)
    {
        item = pop();
        enqueue(item);
    }

    printf("Displaying elements of the queue after reversing:\n");
    display();
}


int main()
{
    top = -1, front = -1, rear = -1;
    int choice;

    printf("Press\n1] Insert\n2] Delete\n3] Display\n4] Reverse\n5]Quit ");

    do
    {
        printf("\nEnter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("Enter element: ");
                    scanf("%d",&item);
                    enqueue(item);
                    break;
            case 2: item = dequeue();
                    if(item == INVALID)
                        printf("Q empty\n");
                    else    
                        printf("Deleted item = %d\n",item);
                    break;
            case 3: display();
                    break;
            case 4: reverse();
                    break;
            case 5: break;
            default: printf("Invalid choice\n");
        }
    }while(choice != 5);


    
}