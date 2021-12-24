// WARP using recursion to search an element in a dynamic array of n integers using binary search
#include <stdio.h>
#include <stdlib.h>
int BinarySearch(int *p, int item, int n);
void input(int *, int);
void main()
{
    int item, n, pos;
    printf("Enter no of elements: ");
    scanf("%d", &n);
    int *p = (int *)calloc(n, sizeof(int));
    printf("Enter %d numbers:", n);
    input(p, n);
    printf("Enter a no to search in an array:");
    scanf("%d", &item);
    pos = BinarySearch(p, item, n);
    if (pos < 0)
        printf("Number NOT present");
    else
        printf("Item present and its position=%d", pos + 1);
}
void input(int *p, int n)
{
    static int i;
    if (i < n)
    {
        scanf("%d", &(*(p + i)));
        i++;
        input(p, n);
    }
}
int BinarySearch(int *p, int item, int n)
{
    static int first = 0;
    int last = n - 1;
    static int mid;
    if (first <= last)
    {
        mid = (first + last) / 2;
        if (p[mid] == item)
            return mid;
        else if (item > p[mid])
            first = mid + 1;
        else
            last = mid - 1;
        first++;
        BinarySearch(p, item, n);
    }
    return -1;
}