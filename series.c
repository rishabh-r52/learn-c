#include <stdio.h>
int fact(int num);
int main()
{
    float i,n,result=0;
    printf("Enter the number of elements: ");
    scanf("%f",&n);
    for(i=1;i<=n;i++)
    {
        result += (i*i)/fact(i);
    }
    printf("Sum of the series = %f\n",result);
    return 0;
}
int fact(int num)
{
    if (num == 1 || num == 0)
        return 1;
    return num*fact(num-1);
}