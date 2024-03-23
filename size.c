#include <stdio.h>
int main()
{
    int x,y,z;
    x = sizeof(34);
    y = sizeof(3.56);
    z = sizeof('b');
    printf("%d %d %d",x,y,z);
    return 0;
}