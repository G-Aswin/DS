//Stack Program with Static Array

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void push(int stack[], int *top, int ele)
{
    if (ele == 0)
    {
        printf("\nEnter element : ");
        scanf("%d", &ele);
    }
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
    int stack[MAX], top = -1;
    int ele;

    int choice = -1;
    while (choice != 4)
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push(stack, &top, 0);
            break;
        case 2:
            ele = pop(stack, &top);
            if (ele != -1)
                printf("\nPopped ele : %d\n", ele);
            break;
        case 3:
            display_stack(stack, &top);
            break;
        default:
            return EXIT_SUCCESS;
        }
    }
    return EXIT_SUCCESS;
}