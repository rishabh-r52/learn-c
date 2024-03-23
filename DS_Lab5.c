#include <stdio.h>
#include <stdlib.h>
int fact(int n)
{
    if(n==1)
        return 1;
    return n*fact(n-1);
}
int main()
{
    int n,result;
    printf("\nRead value for N: ");
    scanf("%d",&n);
    result = fact(n);
    printf("Result: %d\n",result);
    return 0;
}