#include <stdio.h>
int sum(int num[10],int n)
{
    if(n==1)
        return num[0];
    else
        return num[n-1]+sum(num,n-1);
}
int main()
{
    int num[10],n,i,result;
    printf("\nEnter the nth term: ");
    scanf("%d",&n);
    printf("\nRead the array elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    result = sum(num,n);
    printf("Result: %d",result);
    return 0;
}