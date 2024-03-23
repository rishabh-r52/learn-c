#include<stdio.h>
#include<conio.h>
int main()
{
    float N,sqrt,temp;
    printf("Enter the number to find it's square root\n");
    scanf("%f",&N);
    sqrt=N/2;
    temp=0;
    while(sqrt!=temp)
    {
        temp=sqrt,
        sqrt=(N/sqrt+sqrt)/2;
    }
    printf("The square root of %f is %f\n",N,sqrt);
    getch();
    return 0;
}