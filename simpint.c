#include<stdio.h>
int main()
{
    int p,t;
    float r,SI,AM;
    printf("enter the principle and rate and time\n");
    scanf("%d %f %d",&p,&r,&t);
    SI=(p*r*t)/100;
    printf("%f\n",SI);
    AM=SI+p;
    printf("amount = %f",AM);
    return 0;
}