#include <stdio.h>

#define SIZE 5
#define INVALID -9999

int Q[SIZE],front,rear;

void enqueue(int item)
{
        if(front == (rear + 1) %  SIZE)
                printf("Queue Full\n");
        else
	{
		if(front == -1)
			front  =  0;
		rear = (rear + 1) % SIZE;
	        Q[rear] = item;
	}
}

int dequeue()
{
        int item;
        if(front == -1 && rear == -1)
                return INVALID;
        else
        {
                item = Q[front];
		front = (front + 1) % SIZE;
		if (front == (rear + 1) % SIZE)
			front = rear = -1;
                return item; 
        }
}

void display()
{
        int i;

        if(front == -1 && rear == -1)
                printf("Queue is empty\n");
        else
        {
                i = front;
		while(i != rear)
		{
			printf("%d ",Q[i]);
			i = (i + 1) % SIZE;

		}
		printf("%d ",Q[rear]);
                printf("\n");
        }
}

int main()
{
	front = rear = -1;
        char choice;
	int item;
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
                        case '-' : item = dequeue();
                         	   if(item == INVALID)
					printf("Queue Empty\n");
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


