#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    a:puts("Enter Y or N: \n");
    char choice = getchar();
    while(1)
    {
        if(choice=='Y')
        {
            puts("char is Y");
            exit(0);
        }
        else if(choice=='N')
        {
            puts("char is N");
            exit(0);
        }
        else
        {
             while ((getchar()) != '\n' );
                
                puts("invalid");
                goto a;
        }
    }
    return 0;
}