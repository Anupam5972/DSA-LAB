// You are given an array of n+2 elements of the array occur once only between 1 to n, except two nos. which occur twice. find the two repeating nos. in O(n) time complexity.

#include <stdio.h>
void prtRpting(int a[], int size)
{
    int i, j;
    printf("Repeating elements are ");
    for (i = 0; i < size; i++)
        for (j = i + 1; j < size; j++)
            if (a[i] == a[j])
                printf(" %d ", a[i]);
}

int main()
{
    int a[] = {6, 4, 6, 7, 4, 5, 3};
    int a_s = sizeof(a) / sizeof(a[0]);
    prtRpting(a, a_s);

    return 0;
}