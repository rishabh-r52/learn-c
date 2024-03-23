#include <stdio.h>
int main()
{
    int i,n,A[20],temp=0,j;
    printf("Enter the no of element: ");
    scanf("%d",&n);
    printf("Enter elements of A: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    printf("unsorted array:\n");
    for(i=0;i<n;i++)
    {
        printf("%2d",A[i]);
    }
    // for(j=0;j<n-1;j++)
    // {
    //     for(i=0;i<n - j -1;i++)
    //     {
    //         if(A[i]>A[i+1])
    //         {
    //             temp=A[i];
    //             A[i]=A[i+1];
    //             A[i+1]=temp;
    //         }
    //     }
    //     printf("\nSorted array: \n");
    //     for(i=0;i<n;i++)
    //     {
    //         printf("%2d",A[i]);
    //     }
    // }
    for(i=0;i<n;i++) 
    { 
        for(j=i+1;j<n;j++) 
        { 
            if(A[i] > A[j]) 
            { 
                temp = A[i]; 
                A[i] = A[j]; 
                A[j] = temp; 
            } 
        } 
    }
    printf("\nSorted array: \n");
    for(i=0;i<n;i++)
    {
        printf(" %d",A[i]);
    }
return 0;
}