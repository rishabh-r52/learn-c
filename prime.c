#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void printprime(int a, int b);
int isprime(int n);
int main()
{
    int x,a,b;
    printf("enter the range\n");
    scanf("%d %d",&a,&b);
    printprime(a,b);
    return 0;
}
int isprime(int n)
{
    int i;
    if(n==0||n==1)
    return 0;
    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        return 0;
    }
    return 1;
}
void printprime(int a,int b)
{
    int i,j;
    for(j=a;j<b;j++)
    {
        for(i=2;i<=a/2;i++)
        {
            if(a==0||a==1)
                break;
            if(a%i==0)
                break;
            else
            {
                printf("%d",a);
                exit (0);
            }
        }
    }
    return;
}