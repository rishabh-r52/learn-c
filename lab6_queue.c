#include <stdio.h>
#include <stdlib.h>
#define size 5
int q[size], front = 0, rear = -1;
void insert();
void delete();
void display();
int main()
{
    int choice;
    while (choice)
    {
        printf("\nCircular Queue operations\n");
        printf("1.insert\n");
        printf("2.delete\n");
        printf("3.display\n");
        printf("4.exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}
void insert()
{
    int item;
    if ((front == 0 && rear == size - 1) || (front > 0 && rear == front - 1))
        printf("Queue is overflow\n");
    else
    {
        printf("Enter element to be insert:");
        scanf("%d", &item);
        rear = (rear + 1) % size;
        q[rear] = item;
    }
}
void delete ()
{
    int item;
    if (front == 0 && rear == -1)
    {
        printf("Queue is underflow\n");
        exit(1);
    }
    if (front == rear)
    {
        item = q[front];
        front = 0;
        rear = -1;
    }
    else
    {
        item = q[front];
        front = (front + 1) % size;
    }
    printf("Deleted element is:%d\n", item);
}
void display()
{
    int i;
    if (front == 0 && rear == -1)
    {
        printf("Queue is underflow\n");
        exit(1);
    }
    i = front;
    while (i != rear)
    {
        Printf("% d\n", q[i]);
        i = (i + 1) % size;
    }
    printf("%d\n", q[i]);
    printf("\nrear is at %d\n", q[rear]);
    printf("\nfront is at %d\n", q[front]);
}