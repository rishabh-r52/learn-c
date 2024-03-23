#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define SIZE 10
struct stack
{
    int top;
    float data[SIZE];
};
typedef struct stack STACK; //Define STACK as a datatype
void push(STACK *s, float item)
{
    s->data[++(s->top)] = item;
}
float pop(STACK *s)
{
    return s->data[(s->top)--];
}
float operate(char symbol,float op1,float op2)
{
    switch(symbol){
        case '+':
            return op1+op2;
        case '-':
            return op1-op2;
        case '*':
            return op1*op2;
        case '/':
            return op1/op2;
        case '^':
            return pow(op1,op2);
        
    }
}
float postfixeval(STACK *s, char postfix[10])
{
    int i;
    float op1,op2,result;
    char symbol;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        symbol = postfix[i];
        if(isdigit(symbol))
            push(s,symbol-'0');
        else{
            op2 = pop(s);
            op1 = pop(s);
            result = operate(symbol,op1,op2);
            push(s,result);
        }
    }
    return pop(s);
}
int main()
{
    char postfix[10];
    float answer;
    STACK s;
    s.top = -1;
    printf("\nRead Postfix Expression\n");
    scanf("%s", postfix);
    answer = postfixeval(&s, postfix);
    printf("\nThe Final Answer is: %f\n",answer);
    return 0;
}