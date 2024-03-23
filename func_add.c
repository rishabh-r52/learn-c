#include <stdio.h>
void add(int a, int b);
//int add(int a, int b); //Function declaration
int main()
{
    int a=5,b=10;
    add(a,b);
//    int a=5,b=10,D;
//    D=add(a,b); //Function call
//    printf("%d",D);
    return 0;
}

// int add(int a, int b) //Function definition
// { //Function body
//     int c;
//     c=a+b;
//     return c; //return value
// }

void add(int a, int b)
{
    int c;
    // printf("Enter a & b ");
    // scanf("%d %d",&a,&b);
    c=a+b;
    printf("%d",c);
}