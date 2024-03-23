#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int top = -1, data[SIZE];
void push(int item) //Overflow if top > size-1
{
    if(top==(SIZE-1))
        printf("Stack Overflow!\n");
    else{
        top=top+1;
        data[top] = item;
    }
}
void pop()//Underflow if top < 0
{
    if(top==-1)
        printf("Stack Underflow!\n");
    else{
        printf("Item popped is %d\n",data[top]);
        top = top-1;
    }
}
void display()
{
    int i;
    if(top==-1)
        printf("Stack is empty!\n");
    else{
        printf("\nStack Content:\n");
        for(i=top;i>=0;i--)
            printf("%d\n",data[i]);
    }
}
int main(){
    int choice,item;
    for(;;){
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nRead Choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nRead data to be inserted:");
                scanf("%d",&item);
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            default:
                exit(0);
        }
    }
    return 0;
}