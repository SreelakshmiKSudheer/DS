/*
3. Smallest of list of integers using pointers
65) Sreelakshmi K
S2 CSE
Date : 27.09.2023
*/

#include <stdio.h>
#include <stdlib.h>


int main()
{
	int n,i,*p,small;
	printf("How many numbers in the list: ");
	scanf("%d",&n);

	p = (int*) malloc(n * sizeof(int));

	printf("Enter the elements:\n");
	for(i = 0; i < n; i++)
		scanf("%d",p+i);
	
	small = *p;

	for(i = 0; i < n; i++)
	{
		if(*(p + i) < small)
			small = *(p + i);
	}

	printf("Smallest element in the list is %d\n",small);
}


