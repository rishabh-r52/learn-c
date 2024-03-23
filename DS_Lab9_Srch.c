#include <stdio.h>
#include <stdlib.h>
int bins(int n,int a[10],int key,int low,int high){
    int  mid;
    mid = (low + high)/2;
    if(low>high)
        return -1;
    if(a[mid]==key)
        return mid+1;
    if(a[mid]<key)
        return bins(n,a,key,mid+1,high);
    if(a[mid]>key)
        return bins(n,a,key,low,mid-1);
}
int main(){
    int i,n,key,a[10],pos;
    printf("\nRead the nth term: ");
    scanf("%d",&n);
    printf("\nRead the array elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the element to be searched: ");
    scanf("%d",&key);
    pos = bins(n,a,key,0,n-1);
    if(pos==-1)
        printf("\nUnsuccessful Search");
    else
        printf("\nSuccessful Search, Element is at %d\n",pos);
    return 0;
}