#include <stdio.h>
int main()
{
    char op;
    float num1,num2,result;
    printf("Enter the operator: ");
    scanf("%c",&op);
    printf("Enter the first no: ");
    scanf("%f",&num1);
    printf("Enter the second no: ");
    scanf("%f",&num2);
    switch(op)
    {
        case '+':
                result = num1 + num2;
                break;
        case '-':
                result = num1 - num2;
                break;
        case '*':
                result = num1 * num2;
                break;
        case '/':
                if (num2 == 0)
                    printf("Division by zero is not possible.\n");
                else
                    result = num1 / num2;
                break;
        default :
                printf("Invalid operation.\n");
    }
    printf("Result: %0.3f %c %0.3f = %0.3f",num1,op,num2,result);
    return 0;
}