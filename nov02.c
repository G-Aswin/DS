#include <stdio.h>
#include <string.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Program to evaluate postfix
// 1. Set up function to return the priority of each element

//the int stack
#define MAX 5

void push(int stack[], int *top, int ele)
{
    if (*top == MAX - 1)
    {
        printf("\nStack OverFlow!\n");
        return;
    }
    *top = *top + 1;
    stack[*top] = ele;
}

int pop(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("\nStack UnderFlow!\n");
        return -1;
    }

    int ele = stack[*top];
    *top = *top - 1;
    return ele;
}

int solve(int op1, int op2, char operand)
{
    switch (operand)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1*op2;
    case '/':
        return op1/op2;
    case '^':
        return pow(op1, op2);
    
    default:
        printf("\nInvalid OP");
        return -1;
    }
}

int evaluate_postfix(char postfix[20])
{
    int stack[20], top = -1, op1, op2;
    for (int i = 0; i < strlen(postfix); i++)
    {
        if (isdigit(postfix[i]))
        {
            push(stack, &top, postfix[i] - '0');
        }
        else
        {
            op2 = pop(stack, &top);
            op1 = pop(stack, &top);
            push(stack, &top, solve(op1, op2, postfix[i])); 
        }
    }
    return pop(stack, &top);
}

int main()
{
    char postfix_expression[20];

    printf("\nEnter your postfix expression without any space : ");
    scanf("%s", postfix_expression);

    printf("\n\nThe result is  is : %d", evaluate_postfix(postfix_expression));

    return 0;
}