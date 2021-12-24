// WAP Write a menu driven program to perform the following operations of a stack using linked list
// by using suitable user defined functions for each case.
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *ptr;
} * top, *top1, *temp;
void push(int data);
void pop();
void display();
void create();
int count = 0;

void main()
{
    int no, ch, e;
    printf("\n1.Push");
    printf("\n2.Pop");
    printf("\n3.Dipslay");
    printf("\n4.Exit");
    create();
    while (1)
    {
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &no);
            push(no);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Enter correct choice!");
            break;
        }
    }
}
void create()
{
    top = NULL;
}
void push(int data)
{
    if (top == NULL)
    {
        top = (struct node *)malloc(1 * sizeof(struct node));
        top->ptr = NULL;
        top->info = data;
    }
    else
    {
        temp = (struct node *)malloc(1 * sizeof(struct node));
        temp->ptr = top;
        temp->info = data;
        top = temp;
    }
    count++;
}
void display()
{
    top1 = top;
    if (top1 == NULL)
    {
        printf("Stack is empty");
        return;
    }
    while (top1 != NULL)
    {
        printf("%d ", top1->info);
        top1 = top1->ptr;
    }
}
void pop()
{
    top1 = top;
    if (top1 == NULL)
    {
        printf("\n Error: Trying to pop from empty stack ");
        return;
    }
    else
        top1 = top1->ptr;
    printf("\nPopped value: %d \n", top->info);
    free(top);
    top = top1;
    count--;
}