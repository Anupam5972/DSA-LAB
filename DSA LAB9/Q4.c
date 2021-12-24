// Given a sorted array of length n, WAP to find the number in array that appears more than or equal to n/2 times. It can be assumed that such element always exists.
// Input:  2 3 3 4 Output: 3
// Input:  3 4 5 5 5 Output: 5
#include <stdio.h>
int main()
{
    int n;
    printf("Input: ");
    scanf("%d", &n);
    int array[n];
    int max = 0;
    int count;
    int maxelement;
    printf("Output: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    for (int i = 0; i < n; i++)
    {
        count++;
        for (int j = 0; j < n; j++)
        {
            if (array[i] == array[j])
            {
                count++;
            }
        }
        if (count > max)
        {
            max = count;
            maxelement = array[i];
        }
    }
    printf("%d", maxelement);
    return 0;
}