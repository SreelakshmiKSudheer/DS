#include <stdio.h>

#define SIZE 20
int main()
{
    int a[SIZE],n,i,j,small,temp;

    printf("Enter how many elements: ");
    scanf("%d",&n);

    printf("Enter elements: \n");

    for(i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }

    for(i = 0; i < n-1; i++)
    {
        small = i;

        for(j = i+1; j < n; j++)
        {
            if(a[small] > a[j])
            {
                small = j;
            }
        }

        if(i != small)
        {
            temp = a[i];
            a[i] = a[small];
            a[small] = temp;
        }
    }

   printf("Sorted array\n");

    for(i = 0; i < n; i++)
        printf("%d ",a[i]);
    printf("\n");
}