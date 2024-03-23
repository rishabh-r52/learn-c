#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define SIZE 10
struct stack
{
    int top;
    char data[SIZE];
};
typedef struct stack STACK; //Define STACK as a datatype
void push(STACK *s, char item)
{
    s->data[++(s->top)] = item;
}
char pop(STACK *s)
{
    return s->data[(s->top)--];
}
int precede(char symbol)
{
    switch (symbol)
    {
    case '^':
        return 5;
    case '*':
    case '/':
        return 3;
    case '-':
    case '+':
        return 1;
    }
}
void infixtopostfix(STACK *s, char infix[10])
{
    int i, j = 0;
    char temp, symbol, postfix[10];
    for (i = 0; infix[i] != '\0'; i++)
    {
        symbol = infix[i];
        if (isalnum(symbol)) //isalnum checks if operand is alphabet or number
            postfix[j++] = symbol;
        else
        {
            switch (symbol)
            {
            case '(':
                push(s, symbol);
                break;
            case ')':
                temp = pop(s);
                while (temp != '(')
                {
                    postfix[j++] = temp;
                    temp = pop(s);
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                if (s->top == -1 || s->data[s->top] == '(')
                    push(s, symbol);
                else
                {
                    while (precede(s->data[s->top]) >= precede(symbol) && s->top != -1 && s->data[s->top] != '(')
                        postfix[j++] = pop(s);
                    push(s,symbol);
                }
                break;
            }
        }
    }
    while(s->top != -1)
        postfix[j++] = pop(s);
    postfix[j] = '\0';
    printf("\nPostif Expression is: %s\n",postfix);
}
int main()
{
    char infix[10];
    STACK s;
    s.top = -1;
    printf("\nRead infix Expression\n");
    scanf("%s", infix);
    infixtopostfix(&s, infix);
    return 0;
}