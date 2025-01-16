
/*
5.Bubble Sort using pointers
65) Sreelakshmi K
S2 CSE
Date : 27.09.2023
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i,j,n,*p,temp;

	printf("How many elements: ");
	scanf("%d",&n);

	p = (int*)malloc(n * sizeof(int));

	printf("Enter elements: ");
	for(i = 0; i < n; i++)
		scanf("%d",(p+i));

	for(i = 0; i < n;i++)
	{
		for(j = 0;j < n-i-1; j++)
		{
			if(*(p+j) > *(p+j+1))
			{
				temp = *(p+j);
				*(p+j) = *(p+j+1);
				*(p+j+1) = temp;
			}
		}
	}

	printf("Sorted list:\n");
	for(i = 0; i < n; i++ )
		printf("%d ",*(p + i));
	printf("\n");
}
