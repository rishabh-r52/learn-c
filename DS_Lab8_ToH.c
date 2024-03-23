#include <stdio.h>
#include <stdlib.h>
int count=0;
void tower(int n,char s,char d,char t){
    count++;
    if(n == 1)
        printf("\nMove disc %d from %c to %c",n,s,d);
    else{
        tower(n-1,s,t,d);
        printf("\nMove dsic %d from %c to %c",n,s,d);
        tower(n-1,t,d,s);
    }
}
int main(){
    int n;
    printf("\nRead the no. of discs: ");
    scanf("%d",&n);
    tower(n,'S','D','T');
    printf("\n The number of moves is %d\n",count);
    return 0;
}