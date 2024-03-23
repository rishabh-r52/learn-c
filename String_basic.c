#include <stdio.h>
int main(void)
/*{
    int i,n;
    char name[20];
    printf("Enter name: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%c",&name[i]);
    printf("Name: ");
    for(i=0;i<n;i++)
        printf("%c",name[i]);
}*/
{
    char name[20];
    printf("Enter your name: ");
    scanf("%s",name);
    printf("Name: %s",name);
    return 0;
}