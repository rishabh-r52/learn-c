#include <stdio.h>
int fact(int num);
int main()
{
    int N,D;
    scanf("%d",&N);
    D = fact(N);
    printf("%d",D);
    return 0;
}
int fact(int num)
{
    if (num == 1 || num == 0)
        return 1;
    return num*fact(num-1);
}