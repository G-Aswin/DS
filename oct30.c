#include <stdio.h>
#include <string.h>

// Program to convert infix to postfix
// 1. Set up function to return the priority of each element
// 2. Ask the user for the expression in the form of a string
// 3. Go through each element and process the expression to produce the output string.

//the character stack
#define MAX 20

void push(char stack[], int *top, char ele)
{
    if (*top == MAX - 1)
    {
        printf("\nStack OverFlow!\n");
        return;
    }
    *top = *top + 1;
    stack[*top] = ele;
}

char pop(char stack[], int *top)
{
    if (*top == -1)
    {
        printf("\nStack UnderFlow!\n");
        return -1;
    }

    char ele = stack[*top];
    *top = *top - 1;
    return ele;
}
 
//1. Precedence
int stack_precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 2;
    case '/':
    case '*':
        return 4;
    case '^':
    case '$':
        return 5;
    case '(':
        return 0;
    case '#':
        return -1;

    default:
        return 8;
    }
}

int input_precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '/':
    case '*':
        return 3;
    case '^':
    case '$':
        return 6;
    case '(':
        return 9;
    case ')':
        return 0;

    default:
        return 7;
    }
}


//3. Go through each element and form the postfix exp

void infix_to_postfix(char postfix[20], char infix[20])
{
    char stack[20];
    int top = -1;
    int postfix_idx = 0;

    push(stack, &top, '#');

    for (int i = 0; i < strlen(infix); i++)
    {
        while(stack_precedence(stack[top]) > input_precedence(infix[i]))
            postfix[postfix_idx++] = pop(stack, &top);

        if (stack_precedence(stack[top]) != input_precedence(infix[i]))
            push(stack, &top, infix[i]);

        else
            top--;
    }

    while(top != 0)
    {
        postfix[postfix_idx++] = pop(stack, &top);
    }
    postfix[postfix_idx] = '\0';
}

int main()
{
    char infix_expression[20], postfix_expression[20];

    printf("\nEnter your infix expression without any space : ");
    scanf("%s", infix_expression);

    infix_to_postfix(postfix_expression, infix_expression);

    printf("\n\nThe resultant postfix expression is : %s\n", postfix_expression);

    return 0;
}