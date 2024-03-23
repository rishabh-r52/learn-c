#include <stdio.h>
#include <stdlib.h>
int a[10],n,i,pos,val;
void create()
{
    printf("\nEnter the Array Size: ");
    scanf("%d",&n);
    printf("\nEnter array elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
}
void display()
{
    printf("\nArray Elements are:\n");
    for(i=0;i<n;i++)
        printf("a[%d]\t",i);
    printf("\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    printf("\n");
}
void insert()
{
    printf("\nEnter the position to insert element: ");
    scanf("%d",&pos);
    printf("\nEnter the elment to insert: ");
    scanf("%d",&val);
    for(i=n-1;i>=pos;i--)
        a[i+1]=a[i];
    a[pos]=val;
    n++;
}
void delete()
{
    printf("\nEnter the position to be deleted: ");
    scanf("%d",&pos);
    val=a[pos];
    for(i=pos;i<n;i++)
        a[i]=a[i+1];
    n--;
    printf("\nDeleted Element: %d\n",val);
}
int main()
{
    int ch;
    while(1)
    {
        printf("\n-----------------\n");
        printf("1. CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. EXIT\n");
        printf("\n-----------------\n");
        printf("\nEnter Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: create();
                    break;
            case 2: display();
                    break;
            case 3: insert();
                    break;
            case 4: delete();
                    break;
            case 5: exit(0);
            default: printf("\nInvalid Choice!\n");
                    break;
        }
    }
    return 0;
}