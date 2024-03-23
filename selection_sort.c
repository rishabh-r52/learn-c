#include <stdio.h>
int main(void)
{
    int i, min_idx, j, array[10], size, temp;
    printf("Size of array: ");
    scanf("%d",&size);
    printf("Elements of array: ");
    for(i=0;i<size;i++)
    {
        scanf("%d",&array[i]);
    }
    printf("\nUnsorted Array:\t");
    for(i=0;i<size;i++)
    {
        printf("%2d",array[i]);
    }
    for (int j = 0; j < size - 1; j++)
    {
        min_idx = j;
        for (int i = j + 1; i < size; i++)
        {
            if (array[i] < array[min_idx])
                min_idx = i;
        }
        temp = array[min_idx];
        array[min_idx] = array[j];
        array[j] = temp;
    }
    printf("\n\nSorted Array:\t");
    for(i=0;i<size;i++)
    {
        printf("%2d",array[i]);
    }
    return 0;
}