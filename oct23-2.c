//Stack Program with Static Array

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20

void push(char stack[], int *top, char ch)
{
    if (*top == MAX - 1)
    {
        printf("\nStack OverFlow!\n");
        return;
    }
    *top = *top + 1;
    stack[*top] = ch;
}

char pop(char stack[], int *top)
{
    if (*top == -1)
    {
        printf("\nStack UnderFlow!\n");
        return -1;
    }

    char ch = stack[*top];
    *top = *top - 1;
    return ch;
}

void display_stack(char stack[], int *top)
{
    if (*top == -1)
    {
        printf("\nEmpty Stack!\n");
        return;
    }
    printf("\ntop ");
    for (int i = *top; i != -1; i--)
    {
        printf(" -> %c", stack[i]);
    }
}
int main()
{
    char stack[MAX];
    int top = -1;
    char c;

    char str[20];
    printf("\nEnter the string : ");
    scanf("%s", str);

    for (int i = 0; i < strlen(str); i++)
    {
        push(stack, &top, str[i]);
    }

    for (int i = 0; i < strlen(str); i++)
    {
        c = pop(stack, &top);
        if (c != str[i])
        {
            printf("\nNot Palindrome !\n");
            return 0;
        }
    }
    printf("\nString was palindrome.\n");
    return 0;
}