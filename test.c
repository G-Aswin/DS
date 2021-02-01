//Stack Program with Static Array

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20

void push(int stack[], int *top, int ch)
{
    if (*top == MAX - 1)
    {
        printf("\nStack OverFlow!\n");
        return;
    }
    *top = *top + 1;
    stack[*top] = ch;
}

int pop(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("\nStack UnderFlow!\n");
        return -1;
    }

    int ch = stack[*top];
    *top = *top - 1;
    return ch;
}

void display_stack(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("\nEmpty Stack!\n");
        return;
    }
    printf("\ntop ");
    for (int i = *top; i != -1; i--)
    {
        printf(" -> %d", stack[i]);
    }
}
int main()
{
    int stack[MAX];
    int top = -1;
    
    int original;
    printf("Enter the number to check palindrome : ");
    scanf("%d", &original);

    int copy = original;
    //go from back, digit by digit and push into stack
    while (copy != 0)
    {
        push(stack, &top, copy % 10);
        copy /= 10;
    }

    //pop each number from stack and check if it matches with original.
    while (top != -1)
    {
        if (original % 10 != pop(stack, &top))
        {
            printf("Not a palindrome!\n");
            return 0;
        }
        original /= 10;
    }

    printf("The number was palindrome!\n");
    return 0;
}
