#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
struct queue{
    int f;
    int r;
    int data[SIZE];    
};
typedef struct queue CQUEUE;
void enqueue(CQUEUE *q,int item){ // Insertion of Queue Element
    if(q->f==(q->r+1)%SIZE)
        printf("\nCircular Queue is full!\n");
    else{
        q->r = (q->r+1)%SIZE;
        q->data[q->r] = item;
        if(q->f==-1)
            q->f=0;
    }
}
void dequeue(CQUEUE *q){ // Deletion of Queue Element
    if(q->f==-1)
        printf("\nCircular Queue is Empty!\n");
    else{
        printf("\nElement deleted is %d\n",q->data[q->f]);
        if(q->f==q->r){
            q->r=-1;
            q->f=-1;
        }
        else
            q->f = (q->f+1)%SIZE;
    }
}
void display(CQUEUE q){
    int i;
    if(q.f==-1)
        printf("\nCircular Queue is Empty\n");
    else{
        printf("\nCircular Queue Contents:\n");
        for(i=q.f;i!=q.r;i=(i+1)%SIZE)
            printf("%d\t",q.data[i]);
        printf("%d\t",q.data[i]);
    }
}
int main(){
    int choice,item;
    CQUEUE q;
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
//DSA, OS, Network IMP
//girishraosalanke @rvce.edu.in/@gmail.com