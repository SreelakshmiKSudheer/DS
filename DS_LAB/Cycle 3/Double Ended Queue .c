#include <stdio.h>

#define SIZE 5
#define INVALID -99999

int Q[SIZE],front,rear;

void insert_rear(int item)
{
        if(front == (rear + 1) %  SIZE)
                printf("Queue Full\n");
        else
        {
                if(front == -1)
                        front =  0;
                rear = (rear + 1) % SIZE;
                Q[rear] = item;
	}
}

int delete_front()
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

void insert_front(int item)
{
        if((rear == (front - 1) %  SIZE) || (front == 0 && rear == SIZE - 1))
                printf("Queue Full\n");
        else
        {
                if((front == -1 || front == 0) && rear < SIZE-1)
                        front = SIZE - 1;
                else
			front--;
		Q[front] = item;
        }
        
}

int delete_rear()
{
	int item;
        if(front == -1 && rear == -1)
                return INVALID;
        else
        {
		item = Q[rear--];
                if(rear == -1)
                        rear = SIZE - 1;
                if(front == rear + 1)
		{
			 front = -1;
                         rear = -1;
		}
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
               for(i = front; i != rear; i = (i + 1) % SIZE)
                {
                        printf("%d ",Q[i]);
                }
		printf("%d ",Q[i]);
	}
	printf("\n");
}

int main()
{
	front = -1, rear = -1;
	int item;
        char choice;
        printf("Press\n1] To insert front\n2] To Insert rear\n3] To delete from front\n4] To delete fron rear\n5] To display\n6] To quit\n");

        do
        {
                printf("Enter choice: ");
		scanf(" %c",&choice);

	        switch(choice)
                {
                        case '1': printf("Enter an element: ");
                                scanf("%d",&item); 
                                insert_front(item);
                                break;
			case '2': printf("Enter an element: ");
                                scanf("%d",&item); 
                                insert_rear(item);
                                break;

                        case '3' : item = delete_front();
				if(item == INVALID)
					 printf("Queue Empty\n");
				else
                                	printf("Deleted item = %d\n",item);
                                break;
			case '4' : item = delete_rear();
                                if(item == INVALID)
                                         printf("Queue Empty\n");
                                else
                                        printf("Deleted item = %d\n",item);

                                break;

                        case '5': display();
                                break;
                        case '6':
                                break;
                        default: printf("Invalid Choice\n");
                }
        }while(choice != '6');
}

