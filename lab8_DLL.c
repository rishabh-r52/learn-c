#include <stdio.h>
#include <stdlib.h>
void create();
void insert_front();
void insert_end();
void delete_front();
void delete_end();
void display();
typedef struct node
{
    char ssn[10];
    char name[10];
    char dept[10];
    char design[10];
    char sal[10];
    char ph[10];
    struct node *rlink;
    struct node *llink;
} NODE;
NODE *first = NULL;
void main()
{
    int ch;
    while(1)
    {
        printf("\n--------MENU--------\n");
        printf("1: Create\n2: Insert Front\n3: Insert end\n4: Delete Front\n5: Delete End\n6: Display\n7: Exit\n");
        printf("--------------------\n");
        printf("\nEnter Your Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            insert_front();
            break;
        case 3:
            insert_end();
            break;
        case 4:
            delete_front();
            break;
        case 5:
            delete_end();
            break;
        case 6:
            display();
            break;
        case 7:
            exit(0);
        default:
            printf("Wrong Choice");
            break;
        }

    }
}
void create()
{
    int n, i;
    printf("\nEnter No. of Nodes to create: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        insert_end();
    }
}
void insert_front()
{
    NODE *nn;
    nn = (NODE *)malloc(sizeof(NODE));
    printf("\nEnter Employee Details: \n");
    printf("SSN: ");
    scanf("%s", nn->ssn);
    printf("Name: ");
    scanf("%s", nn->name);
    printf("Department: ");
    scanf("%s", nn->dept);
    printf("Designation: ");
    scanf("%s", nn->design);
    printf("salary: ");
    scanf("%s", nn->sal);
    printf("Phone: ");
    scanf("%s", nn->ph);
    if (first == NULL)
    {
        nn->llink = NULL;
        nn->rlink = NULL;
        first = nn;
        return;
    }
    nn->llink = NULL;
    nn->rlink = first;
    first->llink = nn;
    first = nn;
}
void insert_end()
{
    NODE *nn, *temp;
    nn = (NODE *)malloc(sizeof(NODE));
    printf("\nEnter Employee Details:\n");
    printf("SSN: ");
    scanf("%s", nn->ssn);
    printf("Name: ");
    scanf("%s", nn->name);
    printf("Department: ");
    scanf("%s", nn->dept);
    printf("Designation: ");
    scanf("%s", nn->design);
    printf("salary: ");
    scanf("%s", nn->sal);
    printf("Phone: ");
    scanf("%s", nn->ph);
    if (first == NULL)
    {
        nn->rlink = NULL;
        nn->llink = NULL;
        first = nn;
    }
    else
    {
        temp = first;
        while (temp->rlink != NULL)
        {
            temp = temp->rlink;
        }
        nn->rlink = NULL;
        temp->rlink = nn;
        nn->llink = temp;
    }
}
void delete_front()
{
    NODE *temp;
    if (first == NULL)
    {
        printf("\nList is Empty\n");
        return;
    }
    temp = first;
    if (first->rlink == NULL) // NEW CONDITION
    {
        first = NULL;
        free(temp);
        return;
    }
    first = first->rlink;
    first->llink = NULL;
    free(temp);
}
void delete_end()
{
    NODE *temp;
    if (first == NULL)
    {
        printf("\nList is Empty\n");
        return;
    }
    temp = first;
    if (first->rlink == NULL)
    {
        free(temp);
        first = NULL;
        return;
    }
    while (temp->rlink != NULL)
    {
        temp = temp->rlink;
    }
    temp->llink->rlink = NULL;
    free(temp);
}
void display()
{
    int c = 0;
    NODE *temp;
    temp = first;
    if (first == NULL)
    {
        printf("\nLIST IS EMPTY\n");
        return;
    }
    printf("\nEmployee Details: \n");
    printf("SSN\tNAME\tDEPARTMENT\tDESIGNATION\tSALARY\tPHONE\n");
    while (temp != NULL)
    {
        printf("%s\t%s\t%s\t%s\t%s\t%s\n", temp->ssn, temp->name, temp->dept, temp->design, temp->sal, temp->ph);
        temp = temp->rlink;
        c++;
    }
    printf("\nNumber of Nodes = %d\n", c);
}