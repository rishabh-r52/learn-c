// #include <stdio.h>
// int main()
// {
//     int a, b;
//     printf("enter the value of a and b\n");
//     scanf("%d %d", &a, &b);
//     printf("%d\t%d\n", a, b);
//     a = a + b;
//     b = a - b;
//     a = a - b;
//     printf("%d\t%d", a, b);
//     return 0;
// }
// #include <stdio.h>
// int main()
// {
//     int a, b,c;
//     printf("enter the value of a and b\n");
//     scanf("%d %d", &a, &b);
//     printf("%d\t%d\n", a, b);
//     c=a;
//     a=b;
//     b=c;
//     printf("%d\t%d", a, b);
//     return 0;
// }
#include <stdio.h>
int swap(int *a, int *b);
int main()
{
    int a, b;
    int *pa,*pb;
    printf("enter the value of a and b\n");
    scanf("%d %d", &a, &b);
    printf("%d\t%d\n", a, b);
    pa=&a;
    pb=&b;
    swap(pa,pb);
    printf("%d\t%d", a, b);
    return 0;
}
int swap(int *a, int *b)
{
    int c;
    c=*a;
    *a=*b;
    *b=c;
}