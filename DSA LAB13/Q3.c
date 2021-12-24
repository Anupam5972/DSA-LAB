// Wap on Insertion sort find out the time complexity for Best case and worst case.
#include <stdio.h>
#define MAX 100
void ascen(int a[], int n);
void descen(int a[], int n);

int main()
{
    int a[MAX], n;
    int i, j, choice;
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
        ascen(a, n);
        break;
    case 2:
        descen(a, n);
        break;
    }
    return 0;
}
void ascen(int a[], int n)
{
    int i, j, temp;
    for (i = 1; i < (n); i++)
    {
        j = i;
        while (j > 0 && a[j] < a[j - 1])
        {
            temp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = temp;
            j--;
        }
    }
    printf("Array elements in Ascending Order:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void descen(int a[], int n)
{
    int i, j, temp;
    for (i = 1; i < (n); i++)
    {
        j = i;
        while (j > 0 && a[j] < a[j - 1])
        {
            temp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = temp;
            j--;
        }
    }
    for (i = 1; i < (n); i++)
    {
        j = i;
        while (j > 0 && a[j] > a[j - 1])
        {
            temp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = temp;
            j--;
        }
    }
    printf("Array elements in Descending Order:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
