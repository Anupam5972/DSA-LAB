//Write a menu driven program to implement queue operations such as Enqueue, Dequeue, Peek, Display of elements,
//IsEmpty using linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *ptr;
} * front, *rear, *temp, *front1;
int Peek();
void enq(int data);
void deq();
void empty();
void display();
void create();
void main()
{
    int no, ch, e;
        printf("\n 1 - Enque");
        printf("\n 2 - Deque");
        printf("\n 3 - Peek");
        printf("\n 4 - Empty");
        printf("\n 5 - Display");
        printf("\n 6 - Exit");
    create();
    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &no);
            enq(no);
            break;
        case 2:
            deq();
            break;
        case 3:
            e = Peek();
            if (e != 0)
                printf("Front element : %d", e);
            else
                printf("\n No front element in Queue as queue is empty");
            break;
        case 4:
            empty();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("Wrong choice, Please enter correct choice  ");
            break;
        }
    }
}
void create()
{
    front = rear = NULL;
}
void enq(int data)
{
    if (rear == NULL)
    {
        rear = (struct node *)malloc(1 * sizeof(struct node));
        rear->ptr = NULL;
        rear->info = data;
        front = rear;
    }
    else
    {
        temp = (struct node *)malloc(1 * sizeof(struct node));
        rear->ptr = temp;
        temp->info = data;
        temp->ptr = NULL;
        rear = temp;
    }
}
void display()
{
    front1 = front;

    if ((front1 == NULL) && (rear == NULL))
    {
        printf("Queue is empty");
        return;
    }
    while (front1 != rear)
    {
        printf("%d ", front1->info);
        front1 = front1->ptr;
    }
    if (front1 == rear)
        printf("%d", front1->info);
}
void deq()
{
    front1 = front;

    if (front1 == NULL)
    {
        printf("\n Error: Trying to display elements from empty queue");
        return;
    }
    else if (front1->ptr != NULL)
    {
        front1 = front1->ptr;
        printf("\n Dequed value : %d", front->info);
        free(front);
        front = front1;
    }
    else
    {
        printf("\n Dequed value : %d", front->info);
        free(front);
        front = NULL;
        rear = NULL;
    }
}
int Peek()
{
    if ((front != NULL) && (rear != NULL))
        return (front->info);
    else
        return 0;
}
void empty()
{
    if ((front == NULL) && (rear == NULL))
        printf("\n Queue empty");
    else
        printf("Queue not empty");
}