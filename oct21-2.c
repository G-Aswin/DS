//Stack Program with Static Array

#include <stdio.h>
#include <stdlib.h>
#define MAX 3

int* push(int stack[], int *top)
{
    int ele;
    printf("\nEnter the element to be pushed : ");
    scanf("%d", &ele);

    if (*top == MAX - 1)
    {
        stack = (int *)realloc(stack, (*top + 1)*sizeof(int));
        *top = *top + 1; 
        stack[*top] = ele;
        return stack;
    }
    *top = *top + 1;
    stack[*top] = ele;
    return stack;
}

int* pop(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("\nStack UnderFlow!\n");
        return stack;
    }

    int ele = stack[*top];
    *top = *top - 1;
    if (*top != 0)
        stack = (int *)realloc(stack, sizeof(int)*(*top));
        
    printf("\nPopped element is %d", ele);
    return stack;
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
    int* stack = (int*)calloc(MAX, sizeof(int));
    int top = -1;
    int ele;

    int choice = -1;
    while (choice != 4)
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            stack = push(stack, &top);
            break;
        case 2:
            stack = pop(stack, &top);
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