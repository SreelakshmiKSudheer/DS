#include <stdio.h>

#define PRIORITIES 10
#define SIZE 5

int pq[PRIORITIES][SIZE],f[PRIORITIES],r[PRIORITIES];

void enqueue(int item,int prior)
{
	if(prior >= PRIORITIES || prior < 0)
		printf("Given Priority out of range. Give priorities between the range 0 to %d\n",PRIORITIES - 1);
	else
	{
		if(r[prior] ==  SIZE - 1)
			printf("Priority overflow\n");
        	else
        	{
                	if(f[prior] == -1)
                        	f[prior] = 0;
					r[prior] += 1;
                	pq[prior][r[prior]] = item;
        	}
	}
}

int isempty()
{
	int i,empty = 1;
	for(i = 0; i < PRIORITIES;i++)
        {
                if(f[i] != -1)
                {        
                       	empty = 0;
						break;
                }
        }

	return empty;

}

int dequeue()
{
        int item,i;

	if(!(isempty()))
        {
		for(i = PRIORITIES - 1; i >= 0 ; i--)
		{
			if(f[i] != -1)
			{
	        		item = pq[i][f[i]];
				f[i] += 1;
                		if(f[i] == r[i] + 1)
                        		f[i] = r[i] = -1;
				printf("\nDeleted item is %d with priority %d\n",item,i);
                		return item;
			}
        	}
	}
	else
		printf("Q empty\n");
}

void display()
{
        int i,j;

	printf("\n<-------------------------------------------------------->\n");

	if(isempty())
	{
		printf("Q empty\n");
	}
	else
	{
		for(i = PRIORITIES - 1; i >= 0 ; i--)
        	{

	        	if(f[i] == -1)
        	        	printf("No elements with priority %d\n",i);
        		else
        		{
				printf("\nElements with priority %d are\n",i);
                		for(j = f[i]; j != r[i]; j++)
                        		printf("%d\t",pq[i][j]);
				printf("\t%d ",pq[i][j]);
                		printf("\n");
			}
        	}

		printf("\n<-------------------------------------------------------->\n");
	}
}

int main()
{
	int item,prior,i;
        char choice;

	for(i =0; i < PRIORITIES; i++)
	{
		f[i] = -1;
		r[i] = -1;
	}

        printf("Press\n1] To insert\n2] To delete\n3] To display\n4] To quit\n");

        do
        {
                printf("Enter choice: ");
                scanf(" %c",&choice);

                switch(choice)
                {
                        case '1': printf("Enter an element and its priority: ");
                                scanf("%d%d",&item,&prior); 
                                enqueue(item,prior);
                                break;
 
                        case '2' : item = dequeue();
                                break;

                        case '3': display();
                                break;
                        case '4':
                                break;
                        default: printf("Invalid Choice\n");
                }
        }while(choice != '4');

}


