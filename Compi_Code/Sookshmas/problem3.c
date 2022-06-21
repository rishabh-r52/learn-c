#include <stdio.h>
#include <stdlib.h>
int main()
{
    char s[100];
    int x;
    printf("Enter the no of times to display the string( 0 to 9 ): ");
    scanf("%d",&x);
    printf("Enter the string: ");
    scanf("%s",s);
    a:switch(x)
    {
        case 0:
            exit(0);
        default:
            printf("%s\n",s);
            x=x-1;
            goto a;
    }
    return 0;
}