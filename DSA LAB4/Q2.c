#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void display(struct node *start)
{
    struct node *ptr = start;

    printf("traversing the list...\n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
}

struct node *reverse_N(struct node *start, struct node *temp, int n)
{
    struct node *link = NULL, *cur = start, *prev = temp;
    int count = 0;
    while (cur != NULL && (count++) < n)
    {
        link = cur->link;
        cur->link = prev;
        prev = cur;
        cur = link;
    }

    start = prev;
    return start;
}

struct node *creatnode(int d)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = d;
    temp->link = NULL;
    return temp;
}

int main()
{
    printf("creating the linked list by inserting new nodes at the end\n");

    printf("enter 0 to stop building the list, else enter any integer\n");

    int k, count = 0, x = 1, n;

    struct node *curr, *temp;

    scanf("%d", &k);
    struct node *start = creatnode(k);
    scanf("%d", &k);
    temp = start;

    while (k)
    {
        curr = creatnode(k);
        temp->link = curr;
        temp = temp->link;
        x++;
        scanf("%d", &k);
    }
    display(start);
    printf("\nInput N\n");
    while (1)
    {
        scanf("%d", &n);
        if (n < x)
            break;
        printf("N greater than no of element, enter again\n");
    }

    printf("\nreversing upto first N elements...\n");
    temp = start;
    while ((count++) < n)
    {
        temp = temp->link;
    }

    start = reverse_N(start, temp, n);
    display(start);

    return 0;
}