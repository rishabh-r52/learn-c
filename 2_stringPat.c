// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     char str[100],pat[100],rep[100],ans[100];
//     int i,m,c,j,k,flag=0;
//     printf("\nEnter main string: ");
//     gets(str);
//     printf("\nEnter pattern string: ");
//     gets(pat);
//     printf("\nEnter replacement string: ");
//     gets(rep);
//     i=m=c=j=0;
//     while(str[c]!='\0')
//     {
//         if(str[m]==pat[i])
//         {
//             i++;
//             m++;
//             if(pat[i]=='\0')
//             {
//                 for(k=0;rep[k]!='\0';j++,k++)
//                     ans[j]=rep[k];
//                 i=0;
//                 c=m;
//                 flag=1;
//             }
//         }
//         else
//         {
//             ans[j]=str[c];
//             j++;
//             c++;
//             m=c;
//             i=0;
//         }
//     }
//     if(flag==0)
//     {
//         printf("\nPattern not found.");
//     }
//     else
//     {
//         ans[j]='\0';
//         printf("\nResultant String: %s\n",ans);
//     }
// }

#include <stdio.h>
#include <string.h>
int main()
{
    char STR[100],PAT[100],REP[100],ANS[100];
    int c,i,m,j,k,flag,slP,slR,len;
    c=i=m=k=j=flag=len=0;
    printf("\nMain String: ");
    gets(STR);
    printf("\nPattern String: ");
    gets(PAT);
    slP=strlen(PAT);
    printf("\nReplace String: ");
    gets(REP);
    slR=strlen(REP);
    while(STR[i]!='\0')
    {
        if(STR[i]=PAT[j])
        {
            c=i;
            j=len=0;
            while(PAT[j]!='\0')
            {
                if(STR[i]=PAT[j])
                    len++;
                i++;
                j++;
            }
            if(len==slP)
            {
                flag=1;
                for(k=0;k<slR;k++,m++)
                    ANS[m]=REP[k];
            }
            else
            {
                i=c;
            }
        }
        else
        {
            ANS[m]=STR[i];
            m++;
            i++;
        }
    }
    if(flag==0)
    {
        printf("\nPattern not found!");
    }
    else
    {
        ANS[m]='\0';
        printf("\nResultant String: %s\n",ANS);
    }
    getchar();
    return 0;
}