/*
1. Merging 2 sorted arrays so that the merged arrays in ascending order
65) Sreelakshmi K
S2 CSE
Date : 27.09.2023
*/


#include <stdio.h>

int main()
{
	int a[20],b[20],merge[40],m,n,mc = 0,i,j,rem;

	printf("How many elements in list A: ");
	scanf("%d",&m);
	
	printf("How many elements in list B: ");
        scanf("%d",&n);

	printf("Enter the elements of list A:\n");
        for(i = 0; i < m; i++)
                scanf("%d",&a[i]);

	printf("Enter the elements of list B:\n");
        for(i = 0; i < n; i++)
                scanf("%d",&b[i]);

	i = 0, j = 0;

	// merging
	
	while(i < m && j < n)
	{
		if(a[i] == b [j])
		{
			merge[mc++] = a[i++];
			j++;
		}
		else if(a[i] < b[j])
			merge[mc++] = a[i++];
		else
			merge[mc++] = b[j++];
	}

	for(rem = i; rem < m; rem++)
		merge[mc++] = a[rem];

	for(rem = j; rem < n; rem++)
		merge[mc++] = b[rem];

	printf("The merged list is: \n");
	for(i = 0; i < mc; i++)
		printf("%d ",merge[i]);
	printf("\n");
}
