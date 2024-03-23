#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
struct queue{
    int f;
    int r;
    int data[SIZE];    
};
typedef struct queue QUEUE;
void enqueue(QUEUE *q,int item){ // Insertion of Queue Element
    if(q->r==SIZE-1)
        printf("\nQueue is full!\n");
    else{
        q->r = q->r+1;
        q->data[q->r] = item;
        if(q->f==-1)
            q->f=0;
    }
}
void dequeue(QUEUE *q){ // Deletion of Queue Element
    if(q->f==-1)
        printf("\nQueue is Empty!\n");
    else{
        printf("\nElement deleted is %d\n",q->data[q->f]);
        if(q->f==q->r){
            q->r=-1;
            q->f=-1;
        }
        else
            q->f = q->f+1;
    }
}
void display(QUEUE q){
    int i;
    if(q.f==-1)
        printf("\nQueue is Empty\n");
    else{
        printf("\nQueue Contents: ");
        for(i=q.f;i<=q.r;i++)
            printf("%d\t",q.data[i]);
    }
}
int main(){
    int choice,item;
    QUEUE q;
    q.f = -1;
    q.r = -1;
    for(;;){
        printf("\n1.Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nRead Choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nRead data to be inserted:");
                scanf("%d",&item);
                enqueue(&q,item);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(q);
                break;
            default:
                exit(0);
        }
    }
    return 0;
}