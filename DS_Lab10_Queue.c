#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int f=-1,r=-1,data[SIZE];
void enqueue(int item){ // Insertion of Queue Element
    if(r==SIZE-1)
        printf("\nQueue is full!\n");
    else{
        r = r+1;
        data[r] = item;
        if(f==-1)
            f=0;
    }
}
void dequeue(){ // Deletion of Queue Element
    if(f==-1)
        printf("\nQueue is Empty!\n");
    else{
        printf("\nElement deleted is %d\n",data[f]);
        if(f==r){
            r=-1;
            f=-1;
        }
        else
            f = f+1;
    }
}
void display(){
    int i;
    if(f==-1)
        printf("\nQueue is Empty\n");
    else{
        printf("\nQueue Contents: ");
        for(i=f;i<=r;i++)
            printf("%d\t",data[i]);
    }
}
int main(){
    int choice,item;
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
                enqueue(item);
                break;
            case 2:
                dequeue();
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