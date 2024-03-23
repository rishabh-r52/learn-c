#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
struct stack{
    int top;
    int data[SIZE];
};
typedef struct stack STACK; //Define STACK as a datatype
void push(STACK *s, int item) //Overflow if top > size-1
{
    if(s->top==(SIZE-1))
        printf("Stack Overflow!\n");
    else{
        s->top=s->top+1;
        s->data[s->top] = item;
    }
}
void pop(STACK *s)//Underflow if top < 0
{
    if(s->top==-1)
        printf("Stack Underflow!\n");
    else{
        printf("Item popped is %d\n",s->data[s->top]);
        s->top = s->top-1;
    }
}
void display(STACK s)
{
    int i;
    if(s.top==-1)
        printf("Stack is empty!\n");
    else{
        printf("\nStack Content:\n");
        for(i=s.top;i>=0;i--)
            printf("%d\n",s.data[i]);
    }
}
int main(){
    int choice,item;
    STACK s;
    s.top = -1;
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
                push(&s,item);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                display(s);
                break;
            default:
                exit(0);
        }
    }
    return 0;
}