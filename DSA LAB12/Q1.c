// Given an array of 0's and 1's, in O(n) time make all the 0's in one side and all the 1's in other side.

#include <stdio.h>
void Arrange(int a[], int size)
{
    int l = 0, r = size - 1;

    while (l < r)
    {
        while (a[l] == 0 && l < r)
            l++;
        while (a[r] == 1 && l < r)
            r--;
        if (l < r)
        {
            a[l] = 0;
            a[r] = 1;
            l++;
            r--;
        }
    }
}

int main()
{
    int arr[] = {0, 1, 0, 1, 1, 0};
    int a_s = 6, i = 0;

    Arrange(arr, a_s);
    printf("Arranged array is ");
    for (i = 0; i < 6; i++)
        printf("%d ", arr[i]);
    return 0;
}