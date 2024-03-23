#include <stdio.h>
#include <math.h>
int main(void)
{
    float a,b,c,disc,part_r,part_i,root1,root2;
    printf("Enter the coefficients a,b,c of the quadratic equation: ");
    scanf("%f %f %f",&a,&b,&c);
    printf("Quadratic Equation: %0.2f(x^2) + %0.2fx + %0.2f = 0\n",a,b,c);
    disc = b*b - 4*a*c;
    if (disc>0)
    {
        root1 = (-b + sqrt(disc))/2*a;
        root2 = (-b - sqrt(disc))/2*a;
        printf("Roots are real and unequal,\nRoot 1 = %0.2f\nRoot 2 = %0.2f\n",root1,root2);
    }
    else if (disc==0)
    {
        root1 = root2 = -b/2*a;
        printf("Roots are real and equal,\nRoot 1 = %0.2f\nRoot 2 = %0.2f\n",root1,root2);
    }
    else
    {
        part_r = -b/2*a;
        part_i = sqrt(fabs(disc))/2*a;
        printf("Roots are imaginary and unequal,\nRoot 1 = %0.2f + i%0.2f\nRoot 2 = %0.2f - i%0.2f\n",part_r,part_i,part_r,part_i);
    }
    return 0;
}