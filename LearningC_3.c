#include <stdio.h>
int main()
{
    int x,y,z;
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);
    z = x % y;
    printf("The sum is %d", z);
    return 0;
}