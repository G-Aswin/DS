#include <stdio.h>

// Multiple stacks program
#define MAXSIZE 12
#define NoOfStacks 3

void push(int stack[], int bounds[], int top[], int i)
{
    if (top[i] == bounds[i + 1])
    {
        printf("The stack is full!\n");
        return;
    }
    int ele;
    printf("Enter element to be pushed : ");
    scanf("%d", &ele);
    top[i]++;
    stack[top[i]] = ele;
}

int pop(int stack[], int bounds[], int top[], int i)
{
    if (top[i] == bounds[i])
    {
        printf("The stack is empty!\n");
        return -1;
    }
    int ele = stack[top[i]];
    printf("Popping %d from stack number %d\n", ele, i);
    top[i]--;
    return ele;
}

void display(int stack[], int bounds[], int top[])
{
    for (int i = 0; i < NoOfStacks; i++)
    {
        printf("Stack number : %d\n", i);

        if (top[i] == bounds[i])
        {
            printf("Empty\n");
            continue;
        }
        
        for (int j = top[i]; j > bounds[i]; j--)
        {
            printf("%d\n", stack[j]);
        }
    }
}

int main()
{
    int stack[MAXSIZE], bounds[NoOfStacks + 1], top[NoOfStacks + 1], ch, x;
    for (int i = 0; i <= NoOfStacks; i++)
    {
        top[i] = bounds[i] = (MAXSIZE/NoOfStacks)*i - 1;
    }
    while(1)
    {
        printf("\n1.Push\n2.Pop\n3.Display\n\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter your stack number : ");
            scanf("%d", &x);
            if (x < 0 || x >= NoOfStacks)
            {
                printf("Invalid Stack Number\n");
                continue;
            }
            push(stack, bounds, top, x);
            break;
        case 2:
            printf("Enter your stack number : ");
            scanf("%d", &x);
            if (x < 0 || x >= NoOfStacks)
            {
                printf("Invalid Stack Number\n");
                continue;
            }
            pop(stack, bounds, top, x);
            break;
        case 3:
            display(stack, bounds, top);
            break;
        
        default:
            return 0;
        }
    }
}