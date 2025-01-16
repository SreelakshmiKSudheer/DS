/*
1. Linear Search
65) Sreelakshmi K
S2 CSE
Date : 07.10.2023
*/

#include <stdio.h>

int main()
{
	int n,i,a[10],key,present = 0;

	printf("How many elements? ");
	scanf("%d",&n);

	printf("Enter the elements: ");

	for(i = 0; i < n; i++)
		scanf("%d",&a[i]);

	printf("Enter the number to be searched: ");
	scanf("%d",&key);

	for(i = 0; i < n; i++)
	{
		if(a[i] == key)
		{
			present = 1;
			break;
		}
	}
	if(present)
		printf("%d is Present at position %d\n",key,i+1);
	else
		printf("Not present\n");
}
