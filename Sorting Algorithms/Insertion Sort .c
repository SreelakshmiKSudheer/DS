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

    for(i = 1; i < n; i++)
    {
        int key = a[i];
        j = i - 1;

        while(j >= 0 && a[j] > key)
        {
            a[j+1] = a[j];
            j--;
        }

        a[j+1] = key;
    }

    printf("Sorted array\n");

    for(i = 0; i < n; i++)
        printf("%d ",a[i]);
    printf("\n");
}