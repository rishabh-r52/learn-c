#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num = rand();
    printf("%d",num%6);
    return 0;
}
// int random(int a)
// {
//     int i;
//     int num = (rand() % (a + 1));
//     return num;
// }
// int function(int n)
// {
//     int i = 0;
//     if (n <= 0)
//     {
//         return 0;
//     }
//     else
//     {
//         i = random(n - 1);
//         printf("this\n");
//         return function(i) + function(n - 1 - i);
//     }
// }
// int main()
// {
//     function(6);
//     return 0;
// }
