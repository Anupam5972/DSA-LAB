// Wap on Heap sort find out the time complexity for Best case and worst case.
#include <stdio.h>
void ascen(int a[], int n, int i)
{
    int lr = i, temp;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] > a[lr])
        lr = l;

    if (r < n && a[r] > a[lr])
        lr = r;

    if (lr != i)
    {
        temp = a[i];
        a[i] = a[lr];
        a[lr] = temp;
        ascen(a, n, lr);
    }
}
void descen(int a[], int n, int i)
{
    int sm = i, temp;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] < a[sm])
        sm = l;
    if (r < n && a[r] < a[sm])
        sm = r;
    if (sm != i)
    {
        temp = a[i];
        a[i] = a[sm];
        a[sm] = temp;
        descen(a, n, sm);
    }
}

void heapSort(int a[], int n)
{
    int temp;
    for (int i = n / 2 - 1; i >= 0; i--)
        ascen(a, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        ascen(a, i, 0);
    }
}
void heapSort2(int a[], int n)
{
    int temp;
    for (int i = n / 2 - 1; i >= 0; i--)
        descen(a, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        descen(a, i, 0);
    }
}
void printArray(int a[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}
int main()
{
    int a[100];
    int i, j, n, choice;
    printf("Enter total number of elements: ");
    scanf("%d", &n);
    printf("Enter array elements: \n");
    for (i = 0; i < n; i++)
    {
        printf("Enter element %3d: ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("\n1. Ascending Sort\n2. Descending Sort\n");
    printf("\nEnter your Choice : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        heapSort(a, n);
        printf(" Sorted array is \n");
        printArray(a, n);
        break;
    case 2:
        heapSort2(a, n);
        printf(" Sorted array is \n");
        printArray(a, n);
        break;
    }
}