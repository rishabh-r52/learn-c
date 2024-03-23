#include <stdio.h>
#include <stdlib.h>
void push();
void pop();
void display();
typedef struct node
{
    int val;
    struct node*link;
}NODE;
NODE *top=NULL;
void main()
{
    int ch;
    while(1)
    {
        printf("\n1: push\n2: pop\n3: display\n4: exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: push();
	                break;
            case 2: pop();
	                break;
            case 3: display();
	                break;
            case 4: exit(0);
            default: printf("\nInvalid Choice!\n");
                    break;
        }
    }
}
void push()
{
    NODE*nn;
    nn=(NODE*)malloc(sizeof(NODE));
    printf("\nEnter the value: \n");
    scanf("%d",&nn->val);
    nn->link=top;
    top=nn;
}
void pop()
{
    NODE *temp;
    int item;
    if(top==NULL)
    {
        printf("Stack Underflow\n");
        return;
    }
    temp=top;
    item=top->val;
    printf("\nPopped Element: %d\n",top->val);
    top=top->link;
    free(temp);
}
void display()
{
    NODE *temp;
    int count=0;
    if(top==NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    temp=top;
    while(temp!=NULL)
    {
        printf("%d\n",temp->val);
        temp=temp->link;
        count++;
    }
    printf("\nNumber of items in stack: %d\n",count);
}