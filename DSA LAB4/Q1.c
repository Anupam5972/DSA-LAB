#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *create(struct node *start);
void display(struct node *start);
void count(struct node *start);
void search(struct node *start, int data);
struct node *add_beg(struct node *start, int data);
struct node *add_end(struct node *start, int data);
struct node *add_pos(struct node *start, int data, int pos);
struct node *del(struct node *start, int pos);
struct node *del_key(struct node *start, int item);

int main(void)
{
    struct node *start = NULL;
    int choice, pos, data, item;
    while (1)
    {
        printf("1.create list\n");
        printf("2.Traverse\n");
        printf("3.count\n");
        printf("4.search\n");
        printf("5.Add in the beginning\n");
        printf("6.Add in the end\n");
        printf("7.Add at any pos\n");
        printf("8.Delete at any pos\n");
        printf("9.Delete for a given key\n");
        printf("10.quit\n\n");
        printf("enter choice ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            start = create(start);
            break;

        case 2:
            display(start);
            break;

        case 3:
            count(start);
            break;

        case 4:
            printf("enter element to search");
            scanf("%d", &data);
            search(start, data);
            break;

        case 5:
            printf("enter element to add");
            scanf("%d", &data);
            start = add_beg(start, data);
            break;

        case 6:
            printf("enter element to add");
            scanf("%d", &data);
            start = add_end(start, data);
            break;

        case 7:
            printf("enter element to add");
            scanf("%d\n", &data);
            printf("enter position");
            scanf("%d", &pos);
            start = add_pos(start, data, pos);
            break;

        case 8:
            printf("Enter pos");
            scanf("%d", &pos);
            start = del(start, pos);
            break;

        case 9:
            printf("Enter the key=");
            scanf("%d", &data);
            start = del_key(start, data);
            break;

        case 10:
            exit(1);
            break;

        default:
            printf("Error");
            break;
        }
    }
}
void display(struct node *start)
{
    struct node *ptr;
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    ptr = start;
    printf("List is:\n");
    while (ptr != NULL)
    {
        printf("%d\t", ptr->info);
        ptr = ptr->link;
    }
    printf("\n\n");
};

void count(struct node *start)
{
    struct node *ptr;
    int count = 0;
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    ptr = start;
    while (ptr != NULL)
    {
        ptr = ptr->link;
        count++;
    }
    printf("No of elements=%d \n", count);
};
void search(struct node *start, int data)
{
    struct node *ptr;
    int pos = 1;
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    ptr = start;
    printf("List is:\n");
    while (ptr != NULL)
    {
        if (ptr->info == data)
            ;
        {
            printf("item is %d found at %d \n", data, pos);
            return;
        }
        ptr = ptr->link;
        pos++;
    }
    printf("\nItem not found");
};
struct node *add_beg(struct node *start, int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = start;
    start = tmp;
};
struct node *add_end(struct node *start, int data)
{
    struct node *tmp, *ptr;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    ptr = start;
    while (ptr->link != NULL)
        ptr = ptr->link;

    ptr->link = tmp;
    tmp->link = NULL;
    return start;
};
struct node *add_pos(struct node *start, int data, int pos)
{
    struct node *tmp, *ptr;
    int i;
    ptr = start;
    for (i = 1; i < pos - 1 && ptr != NULL; i++)
        ptr = ptr->link;
    if (ptr == NULL)
        printf("error\n");
    else
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->info = data;
        if (pos == 1)
        {
            tmp->link = start;
            start = tmp;
        }
        else
        {
            tmp->link = ptr->link;
            ptr->link = tmp;
        }
    }
    return start;
};
struct node *del_key(struct node *start, int data)
{
    struct node *tmp, *ptr;
    if (start == NULL)
    {
        printf("Empty list");
        return start;
    }
    if (start->info == data)
    {
        tmp = start;
        start = start->link;
        free(tmp);
        return start;
    }
    ptr = start;
    while (ptr->link != NULL)
    {
        if (ptr->link->info == data)
        {
            tmp = ptr->link;
            ptr->link = tmp->link;
            free(tmp);
            return start;
        }
        ptr = ptr->link;
    }
    printf("Element not found\n");
    return start;
};
struct node *del(struct node *start, int pos)
{
    struct node *tmp, *ptr, *temp;
    int i;
    ptr = start;
    if (start == NULL)
    {
        printf("Empty list");
        return start;
    }
    if (pos == 1)
    {
        tmp = start;
        start = start->link;
        free(tmp);
        return start;
    }
    for (i = 1; i <= (pos - 1); i++)
    {
        temp = ptr;
        ptr = ptr->link;
        if (ptr == NULL)
        {
            printf("Invalid pos\n");
        }
        temp->link = ptr->link;
        free(ptr);
        return start;
    }
}
struct node *create(struct node *start)
{
    int i, n, data;
    printf("Enter no of nodes:");
    scanf("%d", &n);
    start = NULL;
    if (n == 0)
        return start;
    printf("Enter element to enter:");
    scanf("%d", &data);
    start = add_beg(start, data);
    for (i = 2; i <= n; i++)
    {
        printf("enter to insert=\n");
        scanf("%d", &data);
        start = add_end(start, data);
    }
    return start;
}