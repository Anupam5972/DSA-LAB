// Given an array, write a program that split even and odd nos.The program should put even nos. first and then odd nos.
#include <stdio.h>
void swap(int *a, int *b);

void seg(int arr[], int size)
{
    int l = 0, r = size - 1;
    while (l < r)
    {
        while (arr[l] % 2 == 0 && l < r)
            l++;
        while (arr[r] % 2 == 1 && l < r)
            r--;
        if (l < r)
        {
            swap(&arr[l], &arr[r]);
            l++;
            r--;
        }
    }
}
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int main()
{
    int arr[] = {2, 3, 4, 5, 6};
    int a_s = sizeof(arr) / sizeof(arr[0]);
    int i = 0;
    seg(arr, a_s);
    printf("Array after Rearanging ");
    for (i = 0; i < a_s; i++)
        printf("%d ", arr[i]);
    return 0;
}