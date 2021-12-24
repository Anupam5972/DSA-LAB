// Given an array container and integer hunt. WAP to find whether hunt is present in container or not. If present, then triple the value of hunt and search again. Repeat these steps until hunt is not found. Finally return the value of hunt.
// Input: container = {1, 2, 3} and hunt = 1 then Output: 9
// Explanation: Start with hunt = 1. Since it is present in array, it becomes 3. Now 3 is present in array and hence hunt becomes 9. Since 9 is a not present, program return 9.
#include <stdio.h>
int main()
{
    int Container[10], c;
    int hunt, i, j, l, n, Flag = 1;

    printf("Enter number of elements in array\n");
    scanf("%d", &n);
    printf("Enter %d integer(s)\n", n);
    for (c = 0; c < n; c++)
        scanf("%d", &Container[c]);
    printf("Enter a number to search\n");
    scanf("%d", &hunt);
    l = sizeof(Container) / sizeof(Container[0]);

    printf("\nInitial Hunt Value = %d", hunt);
    while (Flag == 1)
    {
        Flag = 0;
        for (i = 0; i < l; i++)
        {
            if (hunt == Container[i])
            {
                Flag = 1;
                hunt = hunt * 3;
            }
        }
    }
    printf("\nFinal Hunt Value = %d", hunt);
    return 0;
}