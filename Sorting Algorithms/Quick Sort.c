#include <stdio.h>

#define SIZE 20

void QuickSort(int a[],int low, int high)
{
    if(low >= high)
        return ;
    
    int pivot = a[low];

    int i = low + 1, j = high;

    while(i <= j)
    {
        while(a[i] < pivot)
            i++;
        
        while(a[j] > pivot)
            j--;

        if(i < j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    int temp = a[j];
    a[j] = pivot;
    a[low] = temp;

    QuickSort(a,low,j-1);
    QuickSort(a,j+1,high);

}

int main()
{
    int a[SIZE],n,i;

    printf("Enter how many elements: ");
    scanf("%d",&n);

    printf("Enter elements: \n");

    for(i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }

    QuickSort(a,0,n-1);

    printf("Sorted array\n");

    for(i = 0; i < n; i++)
        printf("%d ",a[i]);
    printf("\n");

}