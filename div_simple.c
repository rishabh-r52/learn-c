#include <stdio.h>
int main()
{
    int remainder=0,num1=99010,num2=3,quotient=0;
    // printf("Enter dividend: ");
    // scanf("%d",&num1);
    // printf("Enter divisor: ");
    // scanf("%d",&num2);
    while(num1>0)
    {
        num1-=num2;
        if(num1<0)
            remainder=num2+num1;
        else
            quotient++;
        
    }
    printf("Remainder = %d\nQuotient = %d\n",remainder,quotient);
    return 0;
}