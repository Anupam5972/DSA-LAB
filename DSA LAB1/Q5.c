#include <stdio.h>
int main()
{

    int arr[10] = {3, 7, 4, 6, 9, 18, 0, 2, 1, 10}, a, b, ctr = 0, counting = 0;
    printf("Array: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nEnter a: ");
    scanf("%d", &a);

    printf("Enter b: ");
    scanf("%d", &b);

    for (int i = 0; i < 10; i++)
    {
        if (arr[i] == a)
        {
            counting = 1;
        }
        if (arr[i] == b)
        {
            break;
        }
        if (counting == 1)
        {
            ctr++;
        }
    }
    if (ctr == 0)
        {
        printf("No element between %d & %d", a, b);
        }
    else{
            printf("\nCounter=%d", ctr + 1);
        }
    return 0;
}
