//Write a program to find out second smallest and second largest in an array

#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements of an array : ");
    
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        int temp;
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] < a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    
    printf("The second smallest element is %d \n", a[n - 2]);
    printf("The second largest element is %d \n", a[1]);
    return 0;
}