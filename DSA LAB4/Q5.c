#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

void rmvDp(struct Node *start)
{
    struct Node *current = start;
    struct Node *next_next;
    if (current == NULL)
        return;
    while (current->link != NULL)
    {
        if (current->data == current->link->data)
        {
            next_next = current->link->link;
            free(current->link);
            current->link = next_next;
        }
        else
        {
            current = current->link;
        }
    }
}
void insertElem(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->link = (*head_ref);
    (*head_ref) = new_node;
}
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->link;
    }
}
int main()
{
    struct Node *start = NULL;
    insertElem(&start, 20);
    insertElem(&start, 13);
    insertElem(&start, 13);
    insertElem(&start, 12);
    insertElem(&start, 12);
    insertElem(&start, 11);
    insertElem(&start, 11);
    printf("\n Linked list before duplicate removal  ");
    printList(start);
    rmvDp(start);
    printf("\n Linked list after duplicate removal ");
    printList(start);
    return 0;
}