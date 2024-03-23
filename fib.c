#include <stdio.h>
int fib(int n);
int main()
{
    int n,F;
    printf("Enter the no. whose fibonacci is to be found\n");
    scanf("%d",&n);
    F=fib(n);
    printf("Fibonacci at %d is %d",n,F);
    return 0;
}
int fib(int n)
{
    if (n==2 || n==1)
        return 1;
    return ( fib(n-2) + fib(n-1) );
}