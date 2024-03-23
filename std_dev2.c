#include <stdio.h>
#include <math.h>
int main()
{
    int i,n;
    float sum=0,diff=0,avg,SD,variance,arr[10];
    float *ptr;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the array elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%f",&arr[i]);
    }
    ptr=arr;
    for(i=0;i<n;i++)
    {
        sum=sum+ptr[i];
    }
    avg=sum/n;
    ptr=arr;
    for(i=0;i<n;i++)
    {
        diff=diff+((*ptr-avg)*(*ptr-avg));
        ptr++;
    }
    variance=diff/n;
    SD=sqrt(variance);
    printf("Variance = %f\n",variance);
    printf("Mean = %f\n",avg);
    printf("Standard Deviation = %f\n",SD);
    return 0;
}