#include <stdio.h>
#include <stdlib.h>
void str_len(char str[]);
void str_cpy(char str1[], char str2[]);
void str_concat(char str1[], char str2[]);
int main()
{
    char str1[100], str2[100];
    int operator;
    printf("What do you want to do: \n");
    printf("string length: 1\nstring copy: 2\nstring concatenation: 3\n");
    scanf("%d", &operator);
    switch (operator)
    {
    case 1:
        printf("str1: ");
        scanf("%[^\n]s",str1);
        printf("String : %s\n",str1);
        str_len(str1);
        break;
    case 2:
        printf("str1: ");
        gets(str1);
        printf("str2: ");
        gets(str2);
        str_cpy(str1, str2);
        break;
    case 3:
        printf("str1: ");
        gets(str1);
        printf("str2: ");
        gets(str2);
        str_concat(str1, str2);
        break;
    default:
        printf("Beta galat dele h tu ");
        break;
    }
}
void str_len(char str1[])
{
    int i;
    for (i = 0; str1[i] = !'\0'; i++);
    printf("String is %d characters long\n", i);
}
void str_cpy(char A[], char B[])
{
    int i, j;
    for (i = 0; B[i] != '\0'; i++)
    {
        A[i] = B[i];
    }
    puts(A);
}
void str_concat(char A[], char B[])
{
    int i, last;
    for (i = 0; A[i] != '\0'; i++)
    {
        last++;
    }
    for (i = 0; B[i] != '\0'; i++)
    {
        A[last] = B[i];
        last++;
    }
    A[last] = '\0';
    puts(A);
}