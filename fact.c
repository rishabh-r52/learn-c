#include <stdio.h>
int fact(int n);
int main()
{
    int n,F;
    printf("Enter the no. whose factorial needs to be calculated\n");
    scanf("%d",&n);
    F=fact(n);
    printf("Factorial of %d is %d",n,F);
    return 0;
}
int fact(int n)
{
    int i;
    if (n==0 || n==1)
        return 1;
    return ( n*fact(n-1) );
}