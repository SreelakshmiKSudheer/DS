#include <stdio.h>

#define SIZE 20
int main()
{
    int a[SIZE],n,i,j;

    printf("Enter how many elements: ");
    scanf("%d",&n);

    printf("Enter elements: \n");

    for(i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    printf("Sorted array\n");

    for(i = 0; i < n; i++)
        printf("%d ",a[i]);
    printf("\n");

}