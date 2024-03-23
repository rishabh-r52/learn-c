#include <stdio.h>
#define PI 3.142
int main()
{
    float rad,H,area,volume;
    printf("Enter radius:");
    scanf("%f", &rad);
    printf("Enter height:");
    scanf("%f", &H);
    area = 2 * PI * rad *(rad+H);
    volume = PI * rad * rad * H;
    printf("area is %f", area);
    printf("volume is %f", volume);
    return 0;
}