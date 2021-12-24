//WAP to arrange the elements of an array so that all even numbers are followed by all odd numbers

#include <stdio.h>
int main()
{
    int a[20], b[20], i, n, j, k, temp, c = 0;
    printf("Enter size of the  array : ");
    scanf("%d", &n);
    printf("Enter elements in array : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] % 2 == 1)
            c++;
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    k = 0;
    j = n - c;
    for (i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            if (k < n - c)
                b[k++] = a[i];
        }
        else
        {
            if (j < n)
                b[j++] = a[i];
        }
    }
    printf("\narray after sorting even and odd elements separately:\n ");
    for (i = 0; i < n; i++)
    {
        a[i] = b[i];
        printf("%d ", a[i]);
    }
}