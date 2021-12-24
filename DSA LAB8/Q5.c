//  A queue data structure is given with enqueue and dequeue operations.
//  WAP to implement a stack using instances of queue data structure and operations on them.
#include <stdio.h>
#include <stdlib.h>
int s[5], top = -1;
void push()
{
    if (top == 4)
        printf("\nStack overflow!!!!");
    else
    {
        printf("\nEnter element to insert:");
        scanf("%d", &s[++top]);
    }
}
void pop()
{
    if (top == -1)
        printf("\nStack underflow!!!");
    else
        printf("\nElement popped is: %d", s[top--]);
}
void disp()
{
    int t = top;
    if (t == -1)
        printf("\nStack empty!!");
    else
        printf("\nStack elements are:\n");
    while (t >= 0)
        printf("%d ", s[t--]);
}
int main()
{
    int ch;
    do
    {
        printf("\n...Stack operations.....\n");
        printf("1.ENQUEUE\n");
        printf("2.DEQUEUE\n");
        printf("3.Display\n");
        printf("4.Exit\n________________\n");
        printf("Enter choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            disp();
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid choice");
        }
    } while (1);
    return 0;
}