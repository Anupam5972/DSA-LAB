#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *current = NULL;
int searchAns = 0;
int deleteData = 0;
//Traversal of the list
void printList()
{
    struct node *ptr = head;
    printf("\n[head] => ");
    while (ptr != NULL)
    {
        printf(" %d =>", ptr->data);
        ptr = ptr->next;
    }

    printf(" [null]\n");
}
void insert(int data)
{
    struct node *link = (struct node *)malloc(sizeof(struct node));
    link->data = data;
    link->next = NULL;
    if (head == NULL)
    {
        head = link;
        return;
    }
    current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = link;
}
// struct node *deletedEL = NULL;
//Delete from any position
void deletePos(int pos)
{
    int tempPos = 1;

    current = head;
    if (head != NULL)
    {
        while (current->next != NULL && tempPos != pos)
        {
            current = current->next;
            tempPos++;
        }
        if (pos == 0)
        {
            head = head->next;
        }
        else if (current->next == NULL && pos == tempPos + 1)
        {
            printf("Position is not valid\n");
        }
        else
        {
            // deletedEL->data = current->next->data;
            deleteData = current->next->data;
            current->next = current->next->next;
        }
    }
    else
    {
        head = NULL;
        printf("List is empty now\n");
    }
}
//Search for item
void findItem(int item)
{
    int pos = 0;
    if (head == NULL)
    {
        printf("Link list empty\n");
    }
    current = head;
    while (current->next != NULL)
    {
        if (current->data == item)
        {
            printf("Item found at pos: %d\n", pos + 1);
            searchAns = pos;
            return;
        }
        current = current->next;
        pos++;
    }
    printf("%d does not exist in the list\n", item);
}
int main()
{
    int searchEl;

    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    printList();
    printf("Enter the element to search: ");
    scanf("%d", &searchEl);
    findItem(searchEl);
    deletePos(searchAns);
    printList();
    insert(deleteData);
    printList();
}