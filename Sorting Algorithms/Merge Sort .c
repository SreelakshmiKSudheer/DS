#include <stdio.h>

#define SIZE 20

void Merge(int a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0, b[SIZE];

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }

    while (i <= mid)
        b[k++] = a[i++];

    while (j <= high)
        b[k++] = a[j++];

    for (int p = 0; p < high - low + 1; p++)
        a[low + p] = b[p];
}

void MergeSort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        MergeSort(a, low, mid);
        MergeSort(a, mid + 1, high);
        Merge(a, low, mid, high);
    }
}

int main()
{
    int a[SIZE], n;

    printf("Enter how many elements: ");
    scanf("%d", &n);

    printf("Enter elements: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    MergeSort(a, 0, n - 1);

    printf("Sorted array\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}
