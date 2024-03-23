   #include <stdio.h>
int main()
{
    int num,rev_num=0,digit,temp;
    printf("Enter the number: ");
    scanf("%d",&num);
    if (num<0)
    {
        printf("Number is not a positive integer.\n");
        return 0;
    }
    temp = num;
    while (num != 0)
    {
        digit = num%10;
        rev_num = rev_num*10 + digit;
        num = num/10;
    }
    if ( rev_num == temp )
        printf("Number is a palindrome.\n");
    else
        printf("Number is not a palindrome.\n");
    return 0;
}