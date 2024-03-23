#include <stdio.h>
#include <string.h>
#include <math.h>
double compute(double op1, char symbol, double op2)
{
    switch (symbol)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    case '^':
        return pow(op1, op2);
    case '%':
        return (int)op1 % (int)op2;
    }
    return 0;
}
int main()
{
    double res, op1, op2, s[20];
    char symbol, postfix[20];
    int value, i, top = -1;
    printf("\nEnter valid postfix expression");
    scanf("%s", postfix);
    for (i = 0; i < strlen(postfix); i++)
    {
        symbol = postfix[i];
        if (isdigit(symbol))
            s[++top] = symbol - '0';
        else if (isalpha(symbol))
        {
            printf("enter the value of %c:", symbol);
            scanf("%d", &value);
            s[++top] = value;
        }
        else
        {
            op2 = s[top--];
            op1 = s[top--];
            res = compute(op1, symbol, op2);
            s[++top] = res;
        }
    }
    printf("the result is %f\n", res);
    return 0;
}