#include <stdio.h>
int main(void)
{
    int i,j,k,a,b,c,A[2][2][2];
    printf("Enter the dimensions of Array in x,y,z respectively:\n");
    scanf("%d %d %d",&i,&j,&k);
    for(a=0;a<i;i++)
    {
        for(b=0;b<j;i++)
        {
            for(c=0;c<k;c++)
            {
                scanf("%d",&A[i][j][k]);
            }
        }
    }
    printf("3D Array: \n\n");
    for(a=0;a<i;i++)
    {
        for(b=0;b<j;i++)
        {
            for(c=0;c<k;c++)
            {
                printf("%2d",A[i][j][k]);
            }
            printf("\n");
        }
        printf("\n\n");
    }
    return 0;
}
// {
//     int i,j,A[5],B[2][3],m,n,k;
//     printf("Enter size of 1D array: ");
//     scanf("%d",&k);
//     for(i=0;i<k;i++)
//         scanf("%d",&A[i]);
//     printf("\nEnter no. of rows & col. in 2D array: ");
//     scanf("%d %d",&m,&n);
//     printf("\nEnter elements of 2D Array: ");
//     for(i=0;i<m;i++)
//     {
//         for(j=0;j<n;j++)
//         {
//             scanf("%d",&B[i][j]);
//         }
//     }
//     printf("\nArray A: ");
//     for(i=0;i<k;i++)
//         printf("%2d",A[i]);
//     printf("\nMatrix B: \n");
//     for(i=0;i<m;i++)
//     {
//         for(j=0;j<n;j++)
//         {
//             printf("%2d",B[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }