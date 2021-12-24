// WAP to determine whether the input sequence of brackets is balanced or not. If a string is balanced, 
// it print YES on a new line; otherwise, print NO on a new line. 
// Example: Input: {[()]} and Output: YES
// Input: {[(])} and Output: NO

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int same(char a, char b)
{
    if (a == '[' && b == ']')
        return 1;
    if (a == '{' && b == '}')
        return 1;
    if (a == '(' && b == ')')
        return 1;
    return 0;
}
int check(char *a)
{
    char stack[1001], top = -1;
    for (int j = 0; j < strlen(a); j++)
    {
        if (a[j] == '[' || a[j] == '{' || a[j] == '(')
            stack[++top] = a[j];
        if (a[j] == ']' || a[j] == '}' || a[j] == ')')
        {
            if (top == -1)
            {
                return 0;
            }
            else
            {
                if (!same(stack[top--], a[j]))
                {
                    return 0;
                }
            }
        }
    }
    if (top != -1)
    {
        return 0;
    }
    return 1;
}
int main()
{
    char a[1001];
    int n, valid;
    printf("enter number of choice of bracket you need to input: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", a);
        valid = check(a);
        if (valid == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}