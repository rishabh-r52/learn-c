#include <stdio.h>
int display(int size,int *ptr);
int main()
{
    int s=10,array[10]={1,2,3,4,5,6,7,8,9,0};
    display(s,&array[0]); //Actual Parameter
    return 0;
}
int display(int size,int *ptr) //Formal Parameter
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d ",*ptr); //Here, the formal parameter namings are used instead of the actual parameters.
        ptr++; //Since pointer was initialized at A[0], ptr++ will change ptr value to the adress of A[1]
    }
}