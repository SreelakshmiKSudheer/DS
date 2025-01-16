/*
3.Stack using array
65) Sreelakshmi K
S2 CSE
Date : 07.10.2023
*/

#include <stdio.h>

int a[10],n,top,item;

void push(int item)
{
	if(top == n - 1)
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
int main()
{
	int i;
	char choice = 't';
	top = -1;

	printf("Enter the size of the stack: ");
	scanf("%d",&n);
		
	while(1)
	{
		printf("Press '+' to insert an element \nor press '-' to delete \nor press 't' to print  all the elements \nor press 'q' to quit : ");
		scanf(" %c",&choice);

		if(choice == '+')
		{
			printf("Enter item: ");
			scanf("%d",&item);
			push(item);
		}
		else if(choice == '-')
		{
			pop();
			printf("Deleted item = %d\n",item);
		}
		else if(choice == 't' && top > -1)
		{
			for(i = 0; i <= top; i++)
				printf("%d ",a[i]);
			printf("\n");
		}
		else if(choice == 'q')
                	break;
		else
			printf("Invalid input\n");

	}
}
