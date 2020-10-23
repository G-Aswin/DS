#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **push(char **stack, int *top)
{
    char name[20];
    printf("\nEnter your name : ");
    scanf("%s", name);

    *top = *top + 1;
    stack = (char **) realloc(stack, sizeof(char)*20*(*top + 1));
    stack[*top] = (char *)calloc(20, sizeof(char));

    strcpy(stack[*top], name);
    return stack;
}

char **pop(char **stack, int *top)
{
    if (*top == -1)
    {
        printf("\nEmpty Stack !");
        return stack;
    }
    char name[20];
    printf("\nPopped name is : %s", stack[*top]);

    *top = *top - 1;
    stack = (char **) realloc(stack, sizeof(char)*20*(*top));

    return stack;
}

void display(char **stack, int *top)
{
    if (*top == -1)
    {
        printf("\nEmpty Stack !\n");
        return;
    }
    for (int i = *top; i >= 0; i--)
    {
        printf("\n %s", stack[i]);
    }
    printf("\n\n");
}

int main()
{
    char **stack;
    stack = (char **) malloc(sizeof(char)*20*2);
    int top = -1, ch;
    while (1)
    {
        printf("\n1.Push\n2.Pop\n3.Display\n\nEnter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            stack = push(stack, &top);
            break;
        case 2:
            stack = pop(stack, &top);
            break;
        case 3:
            display(stack, &top);
            break;
        default:
            return 0;
        }
    }
    return 0;
}