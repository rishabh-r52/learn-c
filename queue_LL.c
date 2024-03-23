#include <stdio.h>
#include <stdlib.h>
void dequeue();
void display();
void enqueue();
typedef struct node
{
    int val;
    struct node*link;
}NODE;
NODE*front=NULL;
void main()
{
    int ch;
    while(1)
    {
        printf("\n1: enqueue\n2: dequeue\n3: display\n4: exit\n");
        printf("Enter your choice\n\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: enqueue();
	                break;
            case 2: dequeue();
	                break;
            case 3: display();
	                break;
            case 4: exit(0);
            default: printf("\nInvalid Choice!\n");
                    break;
        }
    }
}
void dequeue()
{
    NODE *temp;
    if(front==NULL)
    {
        printf("Queue Underflow!\n");
        return;
    }
    temp=front;
    printf("\nDequeued Element: %d",temp->val);
    front=front->link;
    free(temp);
}
void display()
{
    NODE *temp;
    int count=0;
    if(front==NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    temp=front;
    printf("\n");
    while(temp!=NULL)
    {
        printf("%d\t",temp->val);
        temp=temp->link;
        count++;
    }
    printf("\nNumber of items in the queue: %d\n",count);
}
void enqueue()
{
    NODE*nn,*temp;
    nn=(NODE*)malloc(sizeof(NODE));
    printf("\nEnter value \n");
    scanf("%d",&nn->val);
    if(front==NULL)
    {
        nn->link=NULL;
        front=nn;
        return;
    }
    temp=front;
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=nn;
    nn->link=NULL;
}