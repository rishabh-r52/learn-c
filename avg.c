#include <stdio.h>
void average(int a, int b, int c);
void main()
{
    int a,b,c;
    printf("Enter three numbers: ");
    scanf("%d %d %d",&a,&b,&c);
    average(a,b,c);
}
void average(int a, int b, int c)
{
    float avg;
    avg = (a+b+c)/3.0;
    printf("The average of three numbers is %f",avg);
}