#include <stdio.h>
#include <stdlib.h>
void insert_rear();
void insert_front();
void del_rear();
void del_front();
void display();
void create();
typedef struct
{
    char usn[10];
    char name[20];
    char branch[5];
    char sem[5];
    struct NODE *link;
} NODE;
NODE *first = NULL;
void main()
{
    int choice;
    while (1)
    {
        printf("Select an option:\n\n1.Create LL\n2.Display LL\n3.Insert Front\n4.Insert End\n5.Delete Front\n6.Delete End\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert_front();
            break;
        case 4:
            insert_rear();
            break;
        case 5:
            del_front();
            break;
        case 6:
            del_rear();
            break;
        case 7:
            exit(0);
            break;
        default:
            break;
        }
    }
    return 0;
}
void create()
{
    NODE *nn;
    int i, n;
    printf("How many nodes?\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        nn = (NODE *)malloc(sizeof(NODE));
        printf("Enter USN, Name, Sem, Branch:\n");
        scanf("%s%s%s%s", nn->usn, nn->name, nn->sem, nn->branch);
        nn->link = first;
        first = nn;
    }
}
void display()
{
    int count=0;
}