#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct S
{
    int id;
    char name[20];
}student;


void push(student stack[], int *top)
{
    student new;
    printf("\nEnter student id : ");
    scanf("%d", &new.id);
    printf("\nEnter student Name: ");
    scanf("%s", new.name);

    if (*top == MAX - 1)
    {
        printf("\nStack OverFlow!\n");
        return;
    }
    *top = *top + 1;
    stack[*top] = new;
}

student pop(student stack[], int *top)
{
    student ele;
    if (*top == -1)
    {
        printf("\nStack UnderFlow!\n");
        ele.id = -1;
        return ele;
    }

    ele = stack[*top];
    *top = *top - 1;
    return ele;
}

void display_stack(student stack[], int *top)
{
    if (*top == -1)
    {
        printf("\nEmpty Stack!\n");
        return;
    }
    printf("\ntop ");
    for (int i = *top; i != -1; i--)
    {
        printf(" -> |%d , %s|", stack[i].id, stack[i].name);
    }
}
int main()
{
    student stack[MAX], ele;
    int top = -1;

    int choice = -1;
    while (choice != 4)
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push(stack, &top);
            break;
        case 2:
            ele = pop(stack, &top);
            if (ele.id != -1)
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