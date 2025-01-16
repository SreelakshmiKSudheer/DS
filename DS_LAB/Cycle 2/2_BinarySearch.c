/*
2.Binary Search
65) Sreelakshmi K
S2 CSE
Date : 07.10.2023
*/

#include <stdio.h>

int main()
{
	int a[10],n,i,key,present = 0,mid,l,r;

	printf("How many numbers? ");
	scanf("%d",&n);

	printf("Enter the elements in sorted order(ascending): ");
	
	for(i = 0; i < n; i++)
		scanf("%d",&a[i]);

	printf("Enter the number to be searched: ");
	scanf("%d",&key);

	l = 0; r = n - 1;

	while(l <= r)
	{
		present = 0;
		mid = (l + r)/2;

		if(a[mid] == key)
		{
			present = 1;
			break;
		}
		else if(a[mid] > key)
			r = mid - 1;
		else
			l = mid + 1;
	}

	if(present)
		printf("%d is present at %d\n",key,mid+1);
	else
		printf("%d is not present\n",key);
}
