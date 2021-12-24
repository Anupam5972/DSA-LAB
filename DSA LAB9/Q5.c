// WARP (Write a Recursive Program) to search an element in a dynamic array of n integers using linear search.
#include <stdio.h>
int search(int A[], int info, int i, int n)
{
    int pos = 0;
    if (i >= n)
    {
        return 0;
    }
    else if (A[i] == info)
    {
        pos = i + 1;
        return pos;
    }
    else
    {
        return search(A, info, i + 1, n);
    }
    return pos;
}
int main()
{
    int n, info, pos, m = 0, A[10];
    printf("Enter the total elements in the array  ");
    scanf("%d", &n);
    printf("Enter the array elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    printf("Enter the element to search  ");
    scanf("%d", &info);
    pos = search(A, info, 0, n);
    if (pos != 0)
    {
        printf("Element found at pos %d ", pos);
    }
    else
    {
        printf("Element not found");
    }
    return 0;
}