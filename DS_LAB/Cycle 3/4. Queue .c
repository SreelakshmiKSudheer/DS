#include <stdio.h>

#define SIZE 5
#define INVALID -99999

int Q[SIZE],front = -1,rear = -1;

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

int main()
{

	int item;
	char choice;
	printf("Press '+' to INSERT\n'-' to DELETE\n'd' to DISPLAY\n'q' to QUIT: ");
	
	do
	{
		printf("Enter choice: ");
		scanf(" %c",&choice);
		

		switch(choice)
		{
			case '+': printf("Enter an element: ");
				scanf("%d",&item); 
				enqueue(item);
				break;
			case '-' :item =  dequeue();
				if(item == INVALID)
					printf("Queue Underflow\n");
				else
					printf("Deleted item = %d\n",item);
				break;
			case 'd': display();
				break;
			case 'q':
                                break;
			default: printf("Invalid Choice\n");
		}
	}while(choice != 'q');
}
