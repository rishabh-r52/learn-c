/* C program to evaluate a sin(x) using taylor series method */
#include <stdio.h>
#include <math.h>
#define PI 3.142
double fact( double n)
{
    double i,prod=1;
    for(i=1;i<=n;i++)
        prod=prod*i;
    return prod;
}
int main()
{
    double x,sum=0.0,term;
    double i,deg;
    int flag=0;
    printf("Enter the degree for sin \n");
    scanf("%lf",&deg);
    x=fabs(deg)*(PI/180);
    for(i=1;;i=i+2)
    {
        term=pow(x,i)/fact(i);
        if(term<=__FLT_EPSILON__)  
        break;
        if(flag==0)
        {
            sum=sum+term;
            flag=1;
        }
        else
        {
            sum=sum-term;
            flag=0;
        }
    }
    if(deg<0.0)
    {
        printf("user defined sin(%lf)=%lf\n",x,-sum);
        printf("built in sin(%lf)=%lf",x,-sin(x));
    }
    else
    {
        printf("user defined sin(%lf)=%lf\n",x,sum);
        printf("built in sin(%lf)=%lf",x,sin(x));
    }
    return 0;
}