#include<stdio.h>
#include<math.h>
int main()
{
   float a, b, c, d, root1, root2, realPart, imaginaryPart;

   printf("Enter cofficients (a, b, and c): ");
   scanf("%f %f %f", &a, &b, &c);

   printf("The quadratic equation: %.2fx^2+%.2fx+%.2f=0 \n",a,b,c);
   d = (b*b) - 4*a*c; //discriminant

   if( d>1 )
   {
     root1 = (-b+sqrt(d)) / 2*a;
     root2 = (-b-sqrt(d)) / 2*a;
     printf("Roots are %f and %f\n", root1, root2);
   }
   else if(d==0)
   {
     root1 = root2 = -b/2*a;
     printf("Roots are %f and %f\n", root1, root2);
   }
   else
   {
     realPart = -b/2*a;
     imaginaryPart = sqrt(fabs(d))/2*a;
     printf("root1 = %f + i(%f)\n", realPart, imaginaryPart);
     printf("root2 = %f - i(%f)\n", realPart, imaginaryPart);
   }
   return 0;
}