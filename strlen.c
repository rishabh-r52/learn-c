#include <stdio.h>
void str_len(char str[50]);
void main()
{
    char str[10];
    printf("Enter string:\t");
    gets(str);
    str_len(str);
}
void str_len(char str[50])
{
    int len;
    for(len=0;str[len]!='\0';len++);
    printf("\nLength = %d",len);
}