#include <stdio.h>
#include <stdlib.h>
int gcd(int a, int b)
{
    if(a==b)
        return a;
    if(a>b)
        return gcd(a-b,b);
    if(a<b)
        return gcd(b,a);
}
int main()
{
    int a,b,result;
    printf("Enter any two numbers:\n");
    scanf("%d %d",&a,&b);
    result = gcd(a,b);
    printf("\nResult = %d",result);
    return 0;
}