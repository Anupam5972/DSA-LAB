#include <stdio.h>
#include <stdlib.h>

int binary_search(int x, int start, int end, int *array)
{
    int q;

    if (start >= end)
        return -1;

    q = (start + end) / 2;

    if (x == *(array + q))
    {
        return q;
    }
    else if (x > *(array + q))
    {
        return binary_search(x, q + 1, end, array);
    }

    return binary_search(x, start, q - 1, array);
}

int main()
{
    int n, *a, tmp, i, j, search, pos;
    printf("Enter value of n ");
    scanf("%d", &n);
    a = malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        *(a + i) = tmp;
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if ((a + j) > (a + j + 1))
            {
                tmp = *(a + j);
                *(a + j) = *(a + j + 1);
                *(a + j + 1) = tmp;
            }
        }
    }

    printf(" \n Sorted elements are \n");
    for (i = 0; i < n; i++)
    {
        printf(" %d", *(a + i));
    }

    printf(" \n Enter element to search \n");
    scanf("%d", &search);
    pos = binary_search(search, 0, n - 1, &a);
    printf("\n The element is located at position %d \n", pos);

    return 0;
}