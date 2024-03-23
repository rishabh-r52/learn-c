#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char operator;
    float num1,num2,result;
    printf("Select an operation:\nAddition:\t+\nSubtraction:\t-\nMultiplication:\t*\nDivision:\t/\n");
    scanf("%c",&operator);
    if (operator == '+' || operator == '-' || operator == '*' || operator == '/')
    {
        printf("Enter two numbers: ");
        scanf("%f %f",&num1,&num2);
    }
    switch(operator)
    {
        case '+':   result = num1 + num2;
                    break;
        case '-':   result = num1 - num2;
                    break;
        case '*':   result = num1 * num2;
                    break;
        case '/':   if (num2 != 0)
                        result = num1 / num2;
                    else
                    {
                        printf("Division by zero is not possible\n");
                        exit (1);
                    }
                    break;
        default :   printf("Wrong input\n"); 
                    break;
    }
    if (operator == '+' || operator == '-' || operator == '*' || operator == '/')
        printf("%f %c %f = %f\n",num1,operator,num2,result);
    return 0;
}