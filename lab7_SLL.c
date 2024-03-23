#include <stdio.h>
#include <stdlib.h>
void insert_front();
void delete_front();
void display();
void create();
void insert_end();
void delete_end();
typedef struct node
{
    char usn[10];
    char name[25];
    char branch[5];
    char sem[5];
    char ph[10];
    struct node*link;
}NODE;
NODE*first=NULL;
void main()
{
    int ch;
    do
    {
        printf("\n1: create\n2:insert front\n3: delete front \n4:display \n5.Insert End \n6.Delete End\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: create();
	                display();
	                break;
            case 2: insert_front();
	                display();
	                break;
            case 3: delete_front();
	                display();
	                break;
            case 4: display();
	                break;
            case 5: insert_end();
                    display();
                    break;
            case 6: delete_end();
                    display();
                    break;
        }
    }while(ch!=0);
}
void create()
{
    int i,n;
    printf("Enter no. of Nodes to Create: ");
    scanf("%d",&n); //n = 3
    for(i=0;i<n;i++)
    {
        insert_front();
    }
}
void insert_front()
{
    NODE*nn;
    nn=(NODE*)malloc(sizeof(NODE));
    printf("\nEnter student details\n");
    scanf("%s%s%s%s%s",nn->usn,nn->name,nn->branch,nn->sem,nn->ph);
    nn->link=first;
    first=nn;
}
void delete_front()
{
    NODE *temp;
    if(first==NULL)
    {
        printf("List is empty\n");
        return;
    }
    temp=first;
    first=first->link;
    free(temp);
}
void display()
{
    NODE *temp;
    int count=0;
    if(first==NULL)
    {
        printf("List is empty\n");
        return;
    }
    temp=first;
    while(temp!=NULL)
    {
        printf("%s\t%s\t%s\t%s\t%s\n",temp->usn,temp->name,temp->branch,temp->sem,temp->ph);
        temp=temp->link;
        count++;
    }
    printf("\nNumber of nodes in linked list is %d\n",count);
}
void insert_end()
{
    NODE*nn,*temp;
    nn=(NODE*)malloc(sizeof(NODE));
    printf("\nenter student details\n");
    scanf("%s%s%s%s%s",nn->usn,nn->name,nn->branch,nn->sem,nn->ph);
    if(first==NULL)
    {
        nn->link=NULL;
        first=nn;
        return;
    }
    temp=first;
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=nn;
    nn->link=NULL;
}
void delete_end()
{
    NODE*temp,*prev;
    if(first==NULL)
    {
        printf("LIST IS EMPTY");
        return ;
    }
    temp=first;
    while(temp->link!=NULL)
    {
        prev=temp;
        temp=temp->link;
    }
    prev->link=NULL;
    free(temp);
}