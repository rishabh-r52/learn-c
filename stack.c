#include <stdio.h>
#include <stdlib.h>
#define size 5
int s[size];
int top=-1;
int item=0;
void push()
{
    if(top==size-1)
    {
        printf("\nStack Overflow!");
        return;
    }
    printf("\nEnter new element: ");
    scanf("%d",&item);
    s[++top]=item;
}
void pop()
{
    if(top==-1)
    {
        printf("\nStack Underflow!");
        return;
    }
    item=s[top--];
    printf("\nDeleted Element: %d\n",item);
}
void display()
{
    int i;
    if(top==-1)
    {
        printf("\nStack is empty!");
        return;
    }
    printf("\nStack Elements are:\n");
    for(i=top;i>=0;i--)
        printf("%d\n",s[i]);
}
int main()
{
    int ch;
    while(1)
    {
        printf("\n--------MENU--------\n");
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("\n----------------\n");
        printf("Enter Choice: ");
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
            default: printf("\nInvalid Chioce!\n");
                    break;
        }
    }
    return 0;
}