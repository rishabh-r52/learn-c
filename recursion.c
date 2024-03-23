//------------------------FIBONACCI------------------------
#include <stdio.h>
int fib(int n);
int main(void)
{
    int n=0, num;
    printf("Upto element of Fibonacci Series: ");
    scanf("%d",&num);
    printf("\nSeries:\t");
    while(n!=num)
    {
        printf("%d  ", fib(n));
        n++;
    }
    return 0;
}
int fib(int n)
{
    if ( n == 0 )
        return 0;
    if ( n == 1 || n == 2 )
        return 1;
    return fib(n-1) + fib(n-2);
}
//------------------------FACTORIAL------------------------
// #include <stdio.h>
// int factorial(int n);
// int main()
// {
//     int num,result;
//     printf("Enter number: ");
//     scanf("%d",&num);
//     result=factorial(num);
//     printf("\nFactorial = %d",result);
//     return 0;
// }
// int factorial(int n)
// {
//     if (n == 0 || n == 1)
//         return 1;  
//     return n*factorial(n-1);
// }
//------------------------BIN_DECI------------------------
