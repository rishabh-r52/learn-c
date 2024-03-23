#include <stdio.h>
int main()
{
    char *s[1000];
    int i,j,count;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    scanf("%s",s);
    for(j=0;j<=9;j++)
    {
        count=0;
        for(i=0;s[i]!='\0';i++)
        {
            if(s[i]=='0' && j==0)
                count++;
            if(s[i]=='1' && j==1)
                count++;
            if(s[i]=='2' && j==2)
                count++;
            if(s[i]=='3' && j==3)
                count++;
            if(s[i]=='4' && j==4)
                count++;
            if(s[i]=='5' && j==5)
                count++;
            if(s[i]=='6' && j==6)
                count++;
            if(s[i]=='7' && j==7)
                count++;
            if(s[i]=='8' && j==8)
                count++;
            if(s[i]=='9' && j==9)
                count++;
        }
        printf("%d ",count);
    }
    return 0;
}
