#include <stdio.h>
#include <stdlib.h>
#define size 5
int s[size],top=-1,item=0;
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
void pali()
{
    int i,j,flag=0,length=0,len=top+1;
    int num[len],rev[len];
    while(top!=-1)
    {
        num[i]=rev[top]=s[top]; //Reverse Operation
        i++;
        top--;
    }
    printf("\nNumber is: ");
    for(i=0;i<len;i++)
        printf("%d ",num[i]);
    printf("\nReverse is: ");
    for(i=0;i<len;i++)
        printf("%d ",rev[i]);
    for(i=0,j=0;i<len;i++,j++) //Palindrome Operation
        if(num[i]==rev[j])
            length++;
    if(length==len)
        printf("\nNumber is Palindrome!\n");
    else
        printf("\nNumber is not Palindrome!\n");
    top=len-1;
}
int main()
{
    int ch;
    while(1)
    {
        printf("\n--------MENU--------\n");
        printf("\n1. Push\n2. Pop\n3. Check Palindrome\n4. Display\n5. Exit\n");
        printf("\n----------------\n");
        printf("Enter Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: pali();
                    break;
            case 4: display();
                    break;
            case 5: exit(0);
            default: printf("\nInvalid Chioce!\n");
                    break;
        }
    }
    return 0;
}